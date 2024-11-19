/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:58:50 by astefans          #+#    #+#             */
/*   Updated: 2024/11/19 22:09:52 by alicja           ###   ########.fr       */
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
		if (data->philos[i].eat_counter < data->eat_num)
			return (false);
		i++;
	}
	return (true);
}

void	take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_fork(ph);
	pthread_mutex_lock(ph->right_fork);
	print_fork(ph);
}

void	goto_sleep(t_philo *ph)
{
	print_sleeping(ph);
	ft_usleep(ph->data->time_to_sleep);
	//ph->eat_counter++;
}

void	leave_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	goto_sleep(ph);
}
