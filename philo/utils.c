/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:57:39 by astefans          #+#    #+#             */
/*   Updated: 2024/11/22 22:32:16 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!get_dead(philo->data))
		printf("%ld %d is eating\n",
			get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!get_dead(philo->data))
		printf("%ld %d is sleeping\n",
			get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->dead)
		printf("%ld %d is thinking\n",
			get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->dead)
		printf("%ld %d died\n",
			get_time() - philo->data->start_time, philo->id);
	//philo->data->dead = true;
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->dead)
		printf("%ld %d has taken a fork\n",
			get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
