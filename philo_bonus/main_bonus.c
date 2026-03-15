/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:45:00 by girizzi           #+#    #+#             */
/*   Updated: 2026/03/15 18:08:09 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	wait_simulation(t_program *program)
{
	int	i;

	if (program->must_eat != -1)
	{
		i = 0;
		while (i < program->n_philos)
		{
			waitpid(-1, NULL, 0);
			i++;
		}
	}
	else
		sem_wait(program->dead_lock);
	cleanup_simulation(program);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 5 && argc != 6)
	{
		write(2, "Usage: ./philo_bonus 5 800 200 200 [5]\n", 39);
		return (1);
	}
	if (check_args(argv))
		return (1);
	if (init_program(&program, argv))
		return (1);
	init_philos(&program);
	if (start_simulation(&program))
	{
		cleanup_simulation(&program);
		return (1);
	}
	wait_simulation(&program);
	cleanup_simulation(&program);
	return (0);
}
