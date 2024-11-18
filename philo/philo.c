/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:22 by astefans          #+#    #+#             */
/*   Updated: 2024/11/18 19:42:30 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*philo_life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	ph->last_meal = get_time();
	pthread_create(&ph->monitoring, NULL, &check_deaths, ph->data);
	pthread_detach(ph->monitoring);
	if (ph->id % 2 == 0)
		ft_usleep(10);
	while (!ph->data->dead && !did_philos_eat_enough(ph->data))
	{
		print_thinking(ph);
		take_forks(ph);
		print_eating(ph);
		ph->last_meal = get_time();
		ft_usleep(ph->data->time_to_eat);
		leave_forks(ph);
	}
	return (NULL);
}

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
		data->philos[i].last_meal = data->start_time;
		pthread_create(&data->threads[i], NULL, &philo_life, &data->philos[i]);
		i++;
	}
	data->start_time = get_time();
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
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	if (data->forks)
		free(data->forks);
	if (data->threads)
		free(data->threads);
	if (data->philos)
		free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
		usage();
	init_data(&data, argc, argv);
	init_philosophers(&data);
	init_forks(&data);
	start_simulation(&data);
	end_simulation(&data);
	return (0);
}
