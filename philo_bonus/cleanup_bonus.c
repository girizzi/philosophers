/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:40:00 by girizzi           #+#    #+#             */
/*   Updated: 2026/03/06 11:03:02 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_simulation(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_philos)
	{
		kill(program->philos[i].pid, SIGKILL);
		i++;
	}
	sem_close(program->forks);
	sem_close(program->write_lock);
	sem_close(program->meal_lock);
	sem_close(program->dead_lock);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_DEAD);
	free(program->philos);
}
