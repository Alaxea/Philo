/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:59:23 by astefans          #+#    #+#             */
/*   Updated: 2024/11/24 13:56:50 by alicja           ###   ########.fr       */
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
	int		result;
	t_philo *ph = &data->philos[i];
	 
	result = (get_time() - get_last_meal(ph) > data->time_to_die
        && get_last_meal(ph) != -1
        && (data->philos[i].eat_counter < data->eat_num || data->eat_num == -1));
	return (result);
}

int get_dead(t_data *data)
{
    int dead;

    pthread_mutex_lock(&data->dead_mutex);
    dead = data->dead;
    pthread_mutex_unlock(&data->dead_mutex);
    return (dead);
}

static void set_dead(t_data *data, int value)
{
    pthread_mutex_lock(&data->dead_mutex);
    data->dead = value;
    pthread_mutex_unlock(&data->dead_mutex);
}

/*void	*check_deaths(void *void_data)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)void_data;
	while (1)
	{
		if (did_philos_eat_enough(data))
		{
			break ;
		}
		if (check_time_to_die(data, i))
		{
			print_dead(&data->philos[i]);
			set_dead(data, true);
			//data->dead = true;
			break;
		}
		usleep(100);
		i = (i + 1) % data->philo_num;
	}
	return (0);
}*/

/*static int check_time_to_die(t_data *data, int i)
{
    int result;
    long long last_meal;
    int eat_counter;
    t_philo *ph = &data->philos[i];

    // Protect access to shared resources in philo
    pthread_mutex_lock(&ph->meal_mutex);
    last_meal = ph->last_meal;
    eat_counter = ph->eat_counter;
    pthread_mutex_unlock(&ph->meal_mutex);

    result = (get_time() - last_meal > data->time_to_die
              && last_meal != -1
              && (eat_counter < data->eat_num || data->eat_num == -1));

    return result;
}*/


void *check_deaths(void *void_data)
{
    int i = 0;
    t_data *data = (t_data *)void_data;

    while (1)
    {
        if (did_philos_eat_enough(data) || get_dead(data))
        {
			set_dead(data, true);
            break;
        }
        if (check_time_to_die(data, i))
        {
            print_dead(&data->philos[i]);
            set_dead(data, true);
            break;
        }
        usleep(100);
        i = (i + 1) % data->philo_num;
    }

    return (NULL);
}

