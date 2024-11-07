/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:57:39 by astefans          #+#    #+#             */
/*   Updated: 2024/11/07 12:04:29 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void   print_eating(t_philo *philo)
{
    printf("%ld %d is eating\n", get_time() - philo->data->start_time, philo->id);
}

void   print_sleeping(t_philo *philo)
{
    printf("%ld %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
}

void   print_thinking(t_philo *philo)
{
    printf("%ld %d is thinking\n", get_time() - philo->data->start_time, philo->id);
}

void  print_dead(t_philo *philo)
{
    printf("%ld %d died\n", get_time() - philo->data->start_time, philo->id);
}

void   print_fork(t_philo *philo)
{
    printf("%ld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
}

long get_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void ft_usleep(long time)
{
    long start;

    start = get_time();
    while (get_time() - start < time)
        usleep(100);
}

void  usage(void)
{
    printf("Usage: ./philo [number_of_philosophers] [time_to_die]\
     [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
    exit(1);
}