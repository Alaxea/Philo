/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:39:33 by astefans          #+#    #+#             */
/*   Updated: 2024/11/13 17:32:12 by alicja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				eat_counter;
	pthread_t		thread;
	pthread_t		monitoring;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
	long			last_meal;
}					t_philo;

typedef struct s_data
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	long			start_time;
	bool			dead;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;

/*action*/
void	take_forks(t_philo *ph);
void	goto_sleep(t_philo *ph);
void	leave_forks(t_philo *ph);
/*check.c*/
bool	did_philos_eat_enough(t_data *data);
int		ft_atoi(const char *str);
bool	check_atoi(const char *str);
bool	check_args(int argc, char **argv);
void	*check_deaths(void *void_data);
/*init*/
void	init_forks(t_data *data);
void	init_philosophers(t_data *data);
void	init_data(t_data *data, int argc, char **argv);
/*philo*/
void	*philo_life(void *philo);
void	one_philo(t_data *data);
void	start_simulation(t_data *data);
void	end_simulation(t_data *data);
int		main(int argc, char **argv);
/*time*/
long	get_time(void);
void	ft_usleep(int time);
void	usage(void);
/*utils*/
void	print_eating(t_philo *philo);
void	print_sleeping(t_philo *philo);
void	print_thinking(t_philo *philo);
void	print_dead(t_philo *philo);
void	print_fork(t_philo *philo);

#endif