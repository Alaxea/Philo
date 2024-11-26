/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:59:23 by astefans          #+#    #+#             */
/*   Updated: 2024/11/26 14:42:42 by alicja           ###   ########.fr       */
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

void	usage(void)
{
	printf("Usage: ./philo [number_of_philosophers] [time_to_die]\
[time_to_eat] [time_to_sleep]\
[number_of_times_each_philosopher_must_eat]\n");
	exit(1);
}

void	error_input(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("Error: Number of philosophers must be between 1 and 200.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[2]) < 60)
	{
		printf("Error: Time to die must be at least 60 ms.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("Error: Time to eat must be at least 60 ms.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("Error: Time to sleep must be at least 60 ms.\n");
		exit(EXIT_FAILURE);
	}
	if (argv[5] && ft_atoi(argv[5]) < 1)
	{
		printf("Error: Number of meals must be at least 1.\n");
		exit(EXIT_FAILURE);
	}
}
