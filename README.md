# philosophers

A C implementation of the dining philosophers simulation for the 42
Philosophers project, using POSIX threads and mutexes to coordinate access to
shared forks.

## Build and run

The project needs `make`, a C compiler available as `cc`, and a Unix-like
environment with POSIX threads, `gettimeofday`, and `usleep`. On Windows, use a
Linux environment such as WSL with those build tools installed.

From the directory containing this README:

```sh
cd philo
make
./philo 5 800 200 200 5
```

This starts five philosophers with an 800 ms starvation limit, 200 ms eating
time, and 200 ms sleeping time. The simulation stops when a philosopher dies or
every philosopher has eaten at least five meals.

The [Makefile](philo/Makefile) uses `-Wall -Wextra -Werror -pthread` when
compiling, but omits `-pthread` from the link command. If linking fails with
unresolved pthread symbols, build with `make CC="cc -pthread"` so the option is
also passed when linking.

Run these targets from `philo/`:

| Command | Purpose |
| --- | --- |
| `make` or `make all` | Build the `philo` executable. |
| `make clean` | Remove object files. |
| `make fclean` | Remove object files and the executable. |
| `make re` | Remove build outputs and rebuild. |

## Usage

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [meal_nb]
```

Brackets indicate an optional argument; do not type them in the command.

| Argument | Meaning |
| --- | --- |
| `number_of_philosophers` | Number of philosopher threads and forks. |
| `time_to_die` | Maximum time in milliseconds since the start of the last meal, or the simulation start before the first meal. |
| `time_to_eat` | Time in milliseconds spent eating while holding two forks. |
| `time_to_sleep` | Time in milliseconds spent sleeping after eating. |
| `meal_nb` | Optional minimum number of meals for every philosopher before stopping. |

Use positive decimal integers. Zero is rejected for every argument, including
`meal_nb`. Keep values within `INT_MAX`; the parser's overflow check is not
reliable for oversized integers because it accumulates the value in an `int`.

Examples, run from `philo/` after building:

```sh
# No meal limit: runs until a philosopher dies or you interrupt it with Ctrl+C.
./philo 5 800 200 200

# Stop once all philosophers reach five meals, or earlier if one dies.
./philo 5 800 200 200 5

# One philosopher has only one fork and cannot eat; it eventually dies.
./philo 1 800 200 200
```

Status lines contain elapsed milliseconds from the simulation start, a
philosopher ID starting at 1, and an action: `took a fork.`, `is eating.`,
`is sleeping.`, `is thinking.`, or `died.`. Timing and event order depend on
thread scheduling.

A completed simulation returns exit status `0`, including when a philosopher
dies. Argument, initialization, and thread-start failures return `EXIT_FAILURE`;
error messages are printed to standard output.

## How it works

Each philosopher runs in its own thread and alternates between eating, sleeping,
and thinking. There is one mutex per fork. Even and odd philosopher IDs acquire
their forks in opposite orders. Additional mutexes protect shared simulation
state, each philosopher's meal data, and status output.

For more than one philosopher, a monitor thread checks for starvation and the
optional meal target. The single-philosopher case is handled separately.

- [main.c](philo/src/main.c), [parsing.c](philo/src/parsing.c), and
  [init.c](philo/src/init.c): argument handling and simulation setup.
- [routine.c](philo/src/routine.c) and [forks.c](philo/src/forks.c): philosopher
  actions and fork locking.
- [monitor.c](philo/src/monitor.c): termination conditions.
- [status.c](philo/src/status.c), [utils.c](philo/src/utils.c), and
  [exit.c](philo/src/exit.c): output, timing, thread joining, and cleanup.
- [philosophers.h](philo/include/philosophers.h): shared types and declarations.

There is no automated test suite or `make test` target in this repository.

## Norme

The original project notes highlight these **Norme** coding constraints from
the 42 coursework context:

- No `for`, `do while`, `switch`, `case`, or `goto`.
- No more than 25 lines per function and 5 functions per file.
- Separate declarations and assignments, except for static variables.
- At most 80 columns per line, including comments.
- At most 4 named parameters and 5 local variables per function.
