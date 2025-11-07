/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:30:00 by girizzi           #+#    #+#             */
/*   Updated: 2025/11/07 15:03:34 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_isdigit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;;
	}
	return (0);
}

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 1
		|| check_isdigit(argv[1]) == 1)
		return (write(2, "Invalid number of philosophers\n", 31), 1);
	if (ft_atoi(argv[2]) <= 0 || check_isdigit(argv[2]) == 1)
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || check_isdigit(argv[3]) == 1)
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || check_isdigit(argv[4]) == 1)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_isdigit(argv[5]) == 1))
		return (write(2, "Invalid number of lunches\n", 26), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (write(2, "Wrong number of arguments\n", 26), 1);
	if (check_args(argv) == 1)
		return (1);
	init_program();
	init_forks();
	init_philos();
	init_thread();
	free_all();
	return (0);
}

/*
Usage: ./philo <N1> <N2> <N3> <N4> <N5*>

N1: Number of philosophers (max 300)
N2: Time to die
N3: Time to eat
N4: Time to sleep
N5*optional: Number of lunches required
*/