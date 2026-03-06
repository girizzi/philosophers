*This project has been created as part of the 42 curriculum by girizzi.*

# Philosophers 

Welcome to my **Philosophers** project, a deep dive into the world of concurrent programming, race conditions, and synchronization at 42.

## The Challenge
Five philosophers are sitting around a table. In front of them is a bowl of spaghetti and a few forks. They only have three activities: **eating**, **sleeping**, and **thinking**. But there's a catch: to eat, a philosopher needs **two forks**. 

If they don't eat within a certain time, they die of starvation. Balancing their needs while avoiding deadlocks and memory leaks is the core of this assignment.

## Rules
- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively **eat**, **think**, or **sleep**.
- There are as many forks as philosophers.
- A philosopher must take their right and left forks to eat.
- When they finish eating, they put the forks back and start sleeping.
- The simulation stops when a philosopher dies of starvation.
- **Goal**: No philosopher should die!

## Technical Implementation

### Mandatory Part: Threads and Mutexes
In the `philo/` directory, each philosopher is a **thread**. To manage the shared forks, I used **mutexes** (Mutual Exclusion). Every fork is a mutex that can only be "locked" by one philosopher at a time.

- I assigned the forks based on the philosopher's ID to prevent circular wait (a classic deadlock condition).
- To avoid CPU over-consumption, I implemented a delicate monitoring loop that checks the health of all philosophers at high frequency without stalling the simulation.

### Bonus Part: Processes and Semaphores
The `philo_bonus/` directory takes it a step further. Here, philosophers are independent **processes**, and the forks sit in the middle of the table as a **semaphore**.

- Unlike mutexes, semaphores are perfect for managing a pool of identical resources (the forks). 
- Since processes don't share memory, I used a dedicated monitor thread inside each philosopher process to keep track of their own "last meal" timing, allowing for a much more decentralized and robust architecture.

**Precise Timing (`ft_usleep`)**
Standard `usleep` is notoriously imprecise. In a simulation where milliseconds mean the difference between life and death, I implemented a custom `ft_usleep`. It checks the time in small chunks, ensuring that a philosopher never sleeps longer than they should, keeping the simulation perfectly aligned with the subject's strict requirements.

**Thread-Safe Logging**
Printing to the console is a shared resource. I implemented a protected `print_status` function that uses a specific lock to ensure that logs never overlap, and more importantly, that no one prints anything after a philosopher has died.

---

## Usage

### Compilation
Both versions have their own `Makefile`.

**Mandatory:**
```bash
cd philo && make && ./philo 5 800 200 200
```

**Bonus:**
```bash
cd philo_bonus && make && ./philo_bonus 5 800 200 200
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

---

This project adheres to the **42 Norm**, which imposed some "fun" constraints.

❤️ at 42roma.
