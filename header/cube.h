/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:45 by scakmak           #+#    #+#             */
/*   Updated: 2022/10/23 11:30:25 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define RED	"\033[31m"

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
#include "libft.h"

typedef unsigned int	t_bool;
typedef unsigned int	t_uint;



typedef struct s_axis{
    int top;
    int bot;
    int right;
    int left;
    int top_left;
    int top_right;
    int bot_left;
    int bot_right;
    int row;

}   t_axis;

typedef struct s_data
{
	const char	*f_path;
	t_uint		f_size;
    t_uint      f_row_count;
	char		*f_content;
    char        **splited_content;
    char        **config;
    char        *keys[6];
    char        *values[6];
    char        **map;
    unsigned char        f_rgb[3];
    unsigned char        c_rgb[3];
    t_axis  axis;

}				t_data;





void	initialize_data_object(t_data *game, const char *f_path);

t_bool	ends_with(const	char *str, const char *suffix);
void	check_file_exist(const char *file);

t_uint	my_strlen(const char *str);
t_bool contains(char c, char *set);
char	*substr(char const *s, unsigned int start, size_t len);

int get_file_len(t_data *game);
char	*get_file_content(t_data *game);
t_uint  get_row_count(t_data *game);
void    set_split_content(t_data *game);

int row_is_empty(char *s);

void	message_with_exit(t_data *game, const char *message);
void	clear_memory(t_data *game);

#endif