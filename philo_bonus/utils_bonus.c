/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:20:00 by girizzi           #+#    #+#             */
/*   Updated: 2026/03/06 11:02:46 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time, t_program *program)
{
	long long	start;

	(void)program;
	start = get_time();
	while (get_time() - start < time)
		usleep(500);
}

void	print_status(t_philo *philo, char *status)
{
	long long	time;

	sem_wait(philo->program->write_lock);
	time = get_time() - philo->program->start_time;
	printf("%lld %d %s\n", time, philo->id, status);
	if (status[0] != 'd')
		sem_post(philo->program->write_lock);
}
