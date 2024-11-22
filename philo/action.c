/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:58:50 by astefans          #+#    #+#             */
/*   Updated: 2024/11/22 21:02:16 by alicja           ###   ########.fr       */
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

void take_forks(t_philo *ph)
{
    if (ph->id % 2 == 0) {
        // Filozof o parzystym ID bierze najpierw lewy, potem prawy widelec
        pthread_mutex_lock(ph->left_fork);
        //print_fork(ph);
        pthread_mutex_lock(ph->right_fork);
        //print_fork(ph);
    } else {
        // Filozof o nieparzystym ID bierze najpierw prawy, potem lewy widelec
        pthread_mutex_lock(ph->right_fork);
        //print_fork(ph);
        pthread_mutex_lock(ph->left_fork);
        //print_fork(ph);
    }
}

void	goto_sleep(t_philo *ph)
{
	print_sleeping(ph);
	ft_usleep(ph->data->time_to_sleep);
}

void	leave_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	goto_sleep(ph);
}
