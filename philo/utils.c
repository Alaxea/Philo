/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:57:39 by astefans          #+#    #+#             */
/*   Updated: 2024/11/24 15:19:04 by alicja           ###   ########.fr       */
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
void print_thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);  // Locking for printing.
    pthread_mutex_lock(&philo->data->dead_mutex);   // Locking dead flag to prevent race during reading.
    if (!philo->data->dead) {
        printf("%ld %d is thinking\n",
               get_time() - philo->data->start_time, philo->id);
    }
    pthread_mutex_unlock(&philo->data->dead_mutex); // Unlock dead mutex after read.
    pthread_mutex_unlock(&philo->data->print_mutex); // Unlock print mutex.
}

void print_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    pthread_mutex_lock(&philo->data->dead_mutex);   // Lock dead flag to prevent race during reading.
    if (!philo->data->dead) {
        printf("%ld %d died\n", get_time() - philo->data->start_time, philo->id);
        philo->data->dead = true;  // Set dead flag when a philosopher dies.
    }
    pthread_mutex_unlock(&philo->data->dead_mutex);  // Unlock dead mutex after modifying.
    pthread_mutex_unlock(&philo->data->print_mutex);
}

/*void	print_thinking(t_philo *philo)
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
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		printf("%ld %d died\n",
			get_time() - philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->dead_mutex);
	}
	philo->data->dead = true;
	pthread_mutex_unlock(&philo->data->print_mutex);
}*/

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	 pthread_mutex_lock(&philo->data->dead_mutex);
	if (!philo->data->dead)
		printf("%ld %d has taken a fork\n",
			get_time() - philo->data->start_time, philo->id);
	 pthread_mutex_unlock(&philo->data->dead_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
