/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:05:00 by girizzi           #+#    #+#             */
/*   Updated: 2026/03/15 17:12:38 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define PHILO_MAX 300
# define SEM_FORKS "/philo_forks"
# define SEM_WRITE "/philo_write"
# define SEM_MEAL "/philo_meal"
# define SEM_DEAD "/philo_dead"
# define SEM_LIMIT "/philo_limit"

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long long			last_meal;
	pid_t				pid;
	pthread_t			monitor_thread;
	struct s_program	*program;
}	t_philo;

typedef struct s_program
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	long long		start_time;
	sem_t			*forks;
	sem_t			*write_lock;
	sem_t			*meal_lock;
	sem_t			*dead_lock;
	sem_t			*limit;
	t_philo			*philos;
}	t_program;

/* ************************************************************************** */
// FUNCTION PROTOTYPES

// check_args_bonus.c
int			check_args(char **argv);
int			ft_atoi(char *str);

// init_bonus.c
int			init_program(t_program *program, char **argv);
int			init_semaphores(t_program *program);
void		init_philos(t_program *program);

// utils_bonus.c
long long	get_time(void);
void		ft_usleep(long long time, t_program *program);
void		print_status(t_philo *philo, char *status);

// simulation_bonus.c
int			start_simulation(t_program *program);
void		philo_routine(t_philo *philo);
void		*monitor_routine(void *arg);

// cleanup_bonus.c
void		cleanup_simulation(t_program *program);

#endif
