# **philosophers**

## **Objective**
Simulation of a dinner between philosophers with the help of threads and mutexes.<br>

## **Rules**
Each philosopher is a thread.<br>
There's the same number of forks(also threads) as philosophers.<br>
No data races. We are not F1.<br>

## **Usage**
Compile using `make` and run `./philo time_to_die time_to_eat time_to_sleep meal_nb`.<br>
The 5th argument is optional, it sets a benchmark. When every philosopher eats `meal_nb` times simulation stops.<br>
Examples:
```sh
$ ./philo 5 800 200 200
$ ./philo 5 800 200 200 5
```
```
