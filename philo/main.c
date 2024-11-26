/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:22 by astefans          #+#    #+#             */
/*   Updated: 2024/11/26 14:49:06 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	one_philo(t_data *data)
{
	print_thinking(&data->philos[0]);
	ft_usleep(data->time_to_die);
	print_dead(&data->philos[0]);
}

void	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_time();
	if (data->philo_num == 1)
		return (one_philo(data));
	i = 0;
	while (i < data->philo_num)
	{
		pthread_create(&data->threads[i], NULL, &philo_life, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
}

void	end_simulation(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->philos[0].meal_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->threads)
		free(data->threads);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
		usage();
	error_input(argv);
	init_data(&data, argc, argv);
	init_forks(&data);
	init_philosophers(&data);
	start_simulation(&data);
	end_simulation(&data);
	return (0);
}
