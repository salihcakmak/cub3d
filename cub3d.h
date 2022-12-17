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

#ifndef CUB3D_H
# define CUB3D_H

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
# include "./minilibx/mlx.h"

typedef unsigned int	t_bool;
typedef unsigned int	t_uint;

typedef struct s_cub3d
{
	const char	*f_name;
	t_uint		f_size;
	char		*f_content;
    t_uint      f_row_count;
    char        **map;

}				t_cub3d;


void	initialize_cub3d_object(t_cub3d *game);

//init check utils
t_bool	ends_with(const	char *str, const char *suffix);
void	check_file_exist(const char *file);

//string utils
t_uint	my_strlen(const char *str);
t_bool contains(char c, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//file utils
int get_file_len(t_cub3d *game);
char	*get_file_content(t_cub3d *game);
t_uint  get_row_count(t_cub3d *game);
void    set_split_content(t_cub3d *game);

//base utils
void	message_with_exit(t_cub3d *game, const char *message);
void	clear_memory(t_cub3d *game);

// TEST FUNCS

void	test_all(void);
void	test_my_strlen(void);
void	test_ends_with(void);


#endif