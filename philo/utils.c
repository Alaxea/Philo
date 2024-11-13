/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:57:39 by astefans          #+#    #+#             */
/*   Updated: 2024/11/13 17:44:00 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_eating(t_philo *philo)
{
	printf("%ld %d is eating\n",
		get_time() - philo->data->start_time, philo->id);
}

void	print_sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n",
		get_time() - philo->data->start_time, philo->id);
}

void	print_thinking(t_philo *philo)
{
	printf("%ld %d is thinking\n",
		get_time() - philo->data->start_time, philo->id);
}

void	print_dead(t_philo *philo)
{
	printf("%ld %d died\n",
		get_time() - philo->data->start_time, philo->id);
}

void	print_fork(t_philo *philo)
{
	printf("%ld %d has taken a fork\n",
		get_time() - philo->data->start_time, philo->id);
}
