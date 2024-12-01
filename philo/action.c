/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:58:50 by astefans          #+#    #+#             */
/*   Updated: 2024/12/01 17:58:30 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

bool	did_philos_eat_enough(t_data *data)
{
	int	i;

	i = 0;
	if (data->eat_num == -1)
		return (false);
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (data->philos[i].eat_counter < data->eat_num)
		{
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
			return (false);
		}
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	return (true);
}

void	take_forks(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		while (pthread_mutex_lock(ph->left_fork) != 0)
			usleep(10);
		while (pthread_mutex_lock(ph->right_fork) != 0)
		{
			pthread_mutex_unlock(ph->left_fork);
			usleep(10);
		}
	}
	else
	{
		while (pthread_mutex_lock(ph->right_fork) != 0)
			usleep(10);
		while (pthread_mutex_lock(ph->left_fork) != 0)
		{
			pthread_mutex_unlock(ph->right_fork);
			usleep(10);
		}
	}
}

void	go_sleep(t_philo *ph)
{
	print_sleeping(ph);
	ft_usleep(ph->data->time_to_sleep);
}

void	leave_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}
