/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:57:07 by astefans          #+#    #+#             */
/*   Updated: 2024/11/19 15:53:35 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(100);
}

void	usage(void)
{
	printf("Usage: ./philo [number_of_philosophers] [time_to_die]\
[time_to_eat] [time_to_sleep]\
[number_of_times_each_philosopher_must_eat]\n");
	exit(1);
}

void	error_input(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("Error: Number of philosophers must be between 1 and 200.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[2]) < 60)
	{
		printf("Error: Time to die must be at least 60 ms.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("Error: Time to eat must be at least 60 ms.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("Error: Time to sleep must be at least 60 ms.\n");
		exit(EXIT_FAILURE);
	}
	if (argv[5] && ft_atoi(argv[5]) < 1)
	{
		printf("Error: Number of meals must be at least 1.\n");
		exit(EXIT_FAILURE);
	}
}
