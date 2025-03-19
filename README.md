# philosophers

## Contents

<ul style="list-style-type:disc">
  <li><a href="#objective">Objective</a></li>
  <li><a href="#rules">Rules</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#norme">Norme</a></li>
</ul>


## Objective
Simulation of a dinner between philosophers with the help of threads and mutexes.<br>

## Rules
Each philosopher is a thread.<br>
There's the same number of forks as philosophers.<br>
Use mutexes to prevent data races.<br>

## Usage
Compile using `make` and run `./philo time_to_die time_to_eat time_to_sleep meal_nb`.<br>
The 5th argument is optional, it sets a benchmark. When every philosopher eats `meal_nb` times simulation stops.<br>
Examples:
```sh
$ ./philo 5 800 200 200
$ ./philo 5 800 200 200 5
```
## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function
