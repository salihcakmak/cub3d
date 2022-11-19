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
# define BLUE	"\033[34m"
# define RED	"\033[31m"

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef unsigned int	t_bool;
typedef unsigned int	t_uint;

typedef struct s_cub3d
{
	int			fd;
	const char	*f_name;
	t_uint		f_size;
	char		*f_content;
}				t_cub3d;

t_uint	my_strlen(const char *str);
t_bool	ends_with(const	char *str, const char *suffix);
void	initialize_cub3d_object(t_cub3d *game);
void	message_with_exit(t_cub3d *game, const char *message);
void	check_file_exist(const char *file);

// TEST FUNCS
void	test_all(void);
void	test_my_strlen(void);
void	test_ends_with(void);


#endif