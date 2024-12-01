/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:59:23 by astefans          #+#    #+#             */
/*   Updated: 2024/12/01 17:48:42 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	get_dead(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&data->dead_mutex);
	dead = data->dead;
	pthread_mutex_unlock(&data->dead_mutex);
	return (dead);
}

static int	check_time_to_die(t_data *data, int i)
{
	int		result;
	t_philo	*ph;

	ph = &data->philos[i];
	result = (get_time() - get_last_meal(ph) > data->time_to_die
			&& get_last_meal(ph) != -1
			&& (data->philos[i].eat_counter < data->eat_num
				|| data->eat_num == -1));
	return (result);
}

void	set_dead(t_data *data, int value)
{
	pthread_mutex_lock(&data->dead_mutex);
	data->dead = value;
	pthread_mutex_unlock(&data->dead_mutex);
}

void	*check_deaths(void *void_data)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)void_data;
	while (1)
	{
		if (did_philos_eat_enough(data))
			break ;
		if (get_dead(data))
		{
			print_dead(&data->philos[i]);
			break ;
		}
		if (check_time_to_die(data, i))
		{
			print_dead(&data->philos[i]);
			set_dead(data, true);
			break ;
		}
		usleep(50);
		i = (i + 1) % data->philo_num;
	}
	return (NULL);
}
