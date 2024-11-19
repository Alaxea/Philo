/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:59:23 by astefans          #+#    #+#             */
/*   Updated: 2024/11/19 16:21:02 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

bool	check_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (true);
	else
		return (false);
}

bool	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 5 || argc == 6)
		return (true);
	else
	{
		printf("Wrong number of arguments!\n");
		return (false);
	}
	while (i < argc)
	{
		if (!check_atoi(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	check_time_to_die(t_data *data, int i)
{
	return (get_time() - data->philos[i].last_meal > data->time_to_die
		&& data->philos[i].last_meal != -1
		&& (data->philos[i].eat_counter < data->eat_num
			|| data->eat_num == -1));
}

void	*check_deaths(void *void_data)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)void_data;
	while (1)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (did_philos_eat_enough(data) || data->dead)
		{
			pthread_mutex_unlock(&data->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->print_mutex);
		if (check_time_to_die(data, i))
		{
			print_dead(&data->philos[i]);
			data->dead = true;
			pthread_mutex_unlock(&data->print_mutex);
			exit(EXIT_FAILURE);
		}
		usleep(100);
		i = (i + 1) % data->philo_num;
	}
	return (0);
}
