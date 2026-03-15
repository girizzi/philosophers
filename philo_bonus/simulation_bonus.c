/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:30:00 by girizzi           #+#    #+#             */
/*   Updated: 2026/03/15 17:58:03 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->program->meal_lock);
		if (get_time() - philo->last_meal >= philo->program->t_die)
		{
			print_status(philo, "died");
			philo->stop = 1;
			sem_post(philo->program->meal_lock);
			return (NULL);
		}
		if (philo->stop)
		{
			sem_post(philo->program->meal_lock);
			return (NULL);
		}
		sem_post(philo->program->meal_lock);
		usleep(1000);
	}
	return (NULL);
}

static void	eat_routine(t_philo *philo)
{
	sem_wait(philo->program->limit);
	sem_wait(philo->program->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->program->forks);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	sem_wait(philo->program->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	sem_post(philo->program->meal_lock);
	ft_usleep(philo->program->t_eat, philo->program);
	sem_post(philo->program->forks);
	sem_post(philo->program->forks);
	sem_post(philo->program->limit);
}

void	philo_routine(t_philo *philo)
{
	if (pthread_create(&philo->monitor_thread, NULL, &monitor_routine, philo))
		exit(1);
	if (philo->id % 2 == 0)
		ft_usleep(philo->program->t_eat / 2, philo->program);
	while (1)
	{
		sem_wait(philo->program->meal_lock);
		if (philo->stop)
		{
			sem_post(philo->program->meal_lock);
			break ;
		}
		sem_post(philo->program->meal_lock);
		eat_routine(philo);
		if (philo->program->must_eat != -1
			&& philo->meals_eaten >= philo->program->must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->program->t_sleep, philo->program);
		print_status(philo, "is thinking");
	}
	sem_wait(philo->program->meal_lock);
	philo->stop = 1;
	sem_post(philo->program->meal_lock);
	pthread_join(philo->monitor_thread, NULL);
	child_cleanup(philo->program);
	if (get_time() - philo->last_meal >= philo->program->t_die)
		exit(1);
	exit(0);
}

int	start_simulation(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_philos)
	{
		program->philos[i].pid = fork();
		if (program->philos[i].pid == -1)
			return (1);
		if (program->philos[i].pid == 0)
			philo_routine(&program->philos[i]);
		i++;
	}
	return (0);
}
