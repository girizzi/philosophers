# Philosophers - 42 Project

## Overview
This project is a training exercise for multi-threading (Mandatory) and multi-processing (Bonus) using the classical "Dining Philosophers" problem. The goal is to simulate philosophers sitting at a round table, alternating between eating, sleeping, and thinking, without letting any of them die of starvation.

## Rules
- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively **eat**, **think**, or **sleep**.
- There are as many forks as philosophers.
- A philosopher must take their right and left forks to eat.
- When they finish eating, they put the forks back and start sleeping.
- The simulation stops when a philosopher dies of starvation.
- **Goal**: No philosopher should die!

## Mandatory Part (philo/)
In the mandatory version, each philosopher is a **thread** and the forks are protected by **mutexes**.

### Implementation Details:
- **Threads**: Each philosopher runs in its own thread.
- **Mutexes**: Used to prevent data races and ensure that only one philosopher can pick up a specific fork at a time.
- **Monitoring**: A separate logic checks if a philosopher has exceeded the `time_to_die` since their last meal.

## Bonus Part (philo_bonus/)
In the bonus version, each philosopher is a **process** and the forks are represented by a **semaphore**.

### Implementation Details:
- **Processes**: Each philosopher is a child process created via `fork()`.
- **Semaphores**: A named semaphore represents the total number of forks available in the middle of the table.
- **Synchronization**: The main process waits for any child to exit (indicating a death) and then terminates all other processes.

## Usage

### Compilation
Both versions have their own `Makefile`.

**Mandatory:**
```bash
cd philo && make
```

**Bonus:**
```bash
cd philo_bonus && make
```

### Execution
Run the program with the following arguments:
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

#### Arguments:
1. `number_of_philosophers`: The number of philosophers and also the number of forks.
2. `time_to_die` (ms): If a philosopher didn’t start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
3. `time_to_eat` (ms): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
4. `time_to_sleep` (ms): The time a philosopher will spend sleeping.
5. `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Examples
- **Philosopher dies**: `./philo 1 800 200 200`
- **Philosophers survive**: `./philo 5 800 200 200`
- **Simulation with meal limit**: `./philo 5 800 200 200 7`

## Norm Compliance
This project strictly follows the **42 School Norm**:
- Max 5 functions per file.
- Max 25 lines per function.
- Max 5 variables per function.
- Only `while` loops (no `for`).
- No global variables.
- Clear error handling and memory management.
