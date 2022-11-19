/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:20:27 by scakmak           #+#    #+#             */
/*   Updated: 2022/10/23 11:31:57 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_uint	my_strlen(const char *str)
{
	t_uint	len;

	len = 0;
	while (str && *str++)
		len++;
	return (len);
}

t_bool	ends_with(const	char *str, const char *suffix)
{
	t_uint	lenstr;
	t_uint	lensuffix;

	if (!str || !suffix)
		return (0);
	lenstr = my_strlen(str);
	lensuffix = my_strlen(suffix);
	if (lensuffix > lenstr)
		return (0);
	while (lensuffix)
	{
		if (str[lenstr - 1] != suffix[lensuffix - 1])
			return (0);                                                               
		lenstr--;
		lensuffix--;
	}
	return (1);
}

void	open_file(t_cub3d *game)
{
	game->fd = open(game->f_name, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
}

void	set_file_len(t_cub3d *game)
{
	open_file(game);
	game->f_size = 0;
	while (read(game->fd, &(char){0}, 1) > 0)
		game->f_size++;
	close(game->fd);
}

/* char	*read_file_content(t_cub3d *game)
{
	char	*content;

	read(fd, )
} */

void	clear_memory(t_cub3d *game)
{
	//TODO
}

void	message_with_exit(t_cub3d *game, const char *message)
{
	clear_memory(game);
	printf("Error\n%s\n", message);
	exit(1);
}

void	check_game_status(t_cub3d *game)
{
	//TODO
	// check all case, if code block is here. Game must be end.
}

void	check_file_exist(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	close(fd);
	if (fd < 0)
		message_with_exit(NULL, "No such file or directory");
}

void	initialize_cub3d_object(t_cub3d *game)
{
	set_file_len(game);
	//read_file_content(game);
}
