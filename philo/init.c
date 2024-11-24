/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:58:57 by astefans          #+#    #+#             */
/*   Updated: 2024/11/24 11:25:58 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include <stdlib.h>

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_counter = 0;
		data->philos[i].data = data;
		data->philos[i].last_meal = -1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_num];
		pthread_mutex_init(&data->philos[i].meal_mutex, NULL);
		i++;
	}
}
void	free_data(t_data *data)
{
	if (data->threads) 
		free(data->threads);
	if (data->forks) 
		free(data->forks);
	if (data->philos) 
		free(data->philos);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}


void	init_data(t_data *data, int argc, char **argv)
{	
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead = false;
	if (argc == 6)
		data->eat_num = ft_atoi(argv[5]);
	else
		data->eat_num = -1;
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	data->threads = malloc(sizeof(pthread_t) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->threads || !data->forks || !data->philos) 
	{
		perror("malloc failed");
		free_data(data);
		exit(EXIT_FAILURE);
	}
}
