/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:30:00 by girizzi           #+#    #+#             */
/*   Updated: 2025/12/07 12:44:18 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (write(2, "Invalid number of arguments\n", 28), 1);
	if (check_args(argv) == 1)
		return (1);
	init_program(&t_program);
	init_forks(&t_program);
	init_philos(&t_program);
	init_thread(&t_program);
	free_all(&t_program);
	return (0);
}

/*
Usage: ./philo <N1> <N2> <N3> <N4> <N5*>

N1: Number of philosophers (max 300)
N2: Time to die
N3: Time to eat
N4: Time to sleep
N5(*optional): Number of dinners required
*/