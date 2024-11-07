/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicja <alicja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:39:33 by astefans          #+#    #+#             */
/*   Updated: 2024/11/07 12:04:22 by alicja           ###   ########.fr       */
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

typedef struct s_philo
{
    int				id;
    pthread_t		thread;
    pthread_t		death;
    pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;
    struct s_data	*data;
    long			last_meal;
}				t_philo;

typedef struct s_data
{
    int				philo_num;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				eat_num;
    long			start_time;
    pthread_mutex_t	*forks;
    pthread_mutex_t	print;
    t_philo			*philos;
}				t_data;
#endif

