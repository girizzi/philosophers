/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:30:00 by girizzi           #+#    #+#             */
/*   Updated: 2025/11/03 19:46:16 by girizzi          ###   ########.fr       */
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
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
	if
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
