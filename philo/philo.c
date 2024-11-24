/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:22 by astefans          #+#    #+#             */
/*   Updated: 2024/11/24 15:06:25 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

long long get_last_meal(t_philo *ph)
{
    long long last_meal;

    pthread_mutex_lock(&ph->meal_mutex);
    last_meal = ph->last_meal;
    pthread_mutex_unlock(&ph->meal_mutex);
    return last_meal;
}

void set_last_meal(t_philo *ph, long long time)
{
    pthread_mutex_lock(&ph->meal_mutex);
    ph->last_meal = time;
    pthread_mutex_unlock(&ph->meal_mutex);
}

int get_eat_counter(t_philo *ph)
{
    int eat_counter;

    pthread_mutex_lock(&ph->meal_mutex);
    eat_counter = ph->eat_counter;
    pthread_mutex_unlock(&ph->meal_mutex);
    return eat_counter;
}

void *philo_life(void *philo)
{
    t_philo *ph;
    
    ph = (t_philo *)philo;
	pthread_mutex_lock(&ph->meal_mutex);
    ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->meal_mutex);
    pthread_create(&ph->monitoring, NULL, &check_deaths, ph->data);
    if (ph->id % 2 == 0)
        ft_usleep(10);
    while (!get_dead(ph->data) && !did_philos_eat_enough(ph->data))
    {
        print_thinking(ph);
        take_forks(ph);
        print_eating(ph);
        set_last_meal(ph, get_time());
		ph->eat_counter++;
        ft_usleep(ph->data->time_to_eat);
        leave_forks(ph);
		go_sleep(ph);
		print_thinking(ph);
    }
	pthread_join(ph->monitoring, NULL);
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
	int ret;

	data->start_time = get_time();
	if (data->philo_num == 1)
		return (one_philo(data));
	i = 0;
	while (i < data->philo_num)
	{
		//data->philos[i].last_meal = data->start_time;		
		pthread_create(&data->threads[i], NULL, &philo_life, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		ret = pthread_join(data->threads[i], NULL);
		if (ret != 0)
        {
            fprintf(stderr, "Error joining thread %d: %s\n", i, strerror(ret));
            return;
        }
		i++;
	}
}

void	end_simulation(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->philos[0].meal_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->threads)
		free(data->threads);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
		usage();
	error_input(argv);
	init_data(&data, argc, argv);
	init_forks(&data);
	init_philosophers(&data);
	start_simulation(&data);
	end_simulation(&data);
	return (0);
}
