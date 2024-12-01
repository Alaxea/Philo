/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:22 by astefans          #+#    #+#             */
/*   Updated: 2024/12/01 17:50:55 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

long long	get_last_meal(t_philo *ph)
{
	long long	last_meal;

	pthread_mutex_lock(&ph->meal_mutex);
	last_meal = ph->last_meal;
	pthread_mutex_unlock(&ph->meal_mutex);
	return (last_meal);
}

static void	set_last_meal(t_philo *ph, long long time)
{
	pthread_mutex_lock(&ph->meal_mutex);
	ph->last_meal = time;
	pthread_mutex_unlock(&ph->meal_mutex);
}

static void	increment_eat_counter(t_philo *ph)
{
	pthread_mutex_lock(&ph->meal_mutex);
	ph->eat_counter++;
	pthread_mutex_unlock(&ph->meal_mutex);
}

void	*philo_life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	pthread_mutex_lock(&ph->meal_mutex);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->meal_mutex);
	if (ph->id % 2 == 0)
		ft_usleep(10);
	while (!get_dead(ph->data) && !did_philos_eat_enough(ph->data))
	{
		if (ph->eat_counter >= ph->data->eat_num && ph->data->eat_num != -1)
			break ;
		print_thinking(ph);
		take_forks(ph);
		print_eating(ph);
		set_last_meal(ph, get_time());
		increment_eat_counter(ph);
		ft_usleep(ph->data->time_to_eat);
		leave_forks(ph);
		go_sleep(ph);
	}
	return (NULL);
}
