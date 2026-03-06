/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:15:00 by girizzi           #+#    #+#             */
/*   Updated: 2026/03/06 11:02:44 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_program *program)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_DEAD);
	program->forks = sem_open(SEM_FORKS, O_CREAT, 0644, program->n_philos);
	program->write_lock = sem_open(SEM_WRITE, O_CREAT, 0644, 1);
	program->meal_lock = sem_open(SEM_MEAL, O_CREAT, 0644, 1);
	program->dead_lock = sem_open(SEM_DEAD, O_CREAT, 0644, 1);
	if (program->forks == SEM_FAILED || program->write_lock == SEM_FAILED
		|| program->meal_lock == SEM_FAILED || program->dead_lock == SEM_FAILED)
		return (1);
	return (0);
}

int	init_program(t_program *program, char **argv)
{
	program->n_philos = ft_atoi(argv[1]);
	program->t_die = ft_atoi(argv[2]);
	program->t_eat = ft_atoi(argv[3]);
	program->t_sleep = ft_atoi(argv[4]);
	program->must_eat = -1;
	if (argv[5])
		program->must_eat = ft_atoi(argv[5]);
	program->start_time = get_time();
	if (init_semaphores(program))
		return (1);
	return (0);
}

void	init_philos(t_program *program)
{
	int	i;

	program->philos = malloc(sizeof(t_philo) * program->n_philos);
	if (!program->philos)
		return ;
	i = 0;
	while (i < program->n_philos)
	{
		program->philos[i].id = i + 1;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal = program->start_time;
		program->philos[i].program = program;
		i++;
	}
}
