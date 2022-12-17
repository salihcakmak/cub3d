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


void	check_game_status(t_cub3d *game)
{

	//TODO
	// check all case, if code block is here. Game must be end.
}

void    check_possible_character(t_cub3d *game)
{
    int i;

    i = 0;
    while (game->f_content[i])
    {
        if (!contains(game->f_content[i], "01NSEW"))
            message_with_exit(game, "Only 6 possible characters!!");
        i++;
    }
}

void	initialize_cub3d_object(t_cub3d *game)
{
    game->f_size = get_file_len(game);
    game->f_content = get_file_content(game);
    game->f_row_count = get_row_count(game);
    set_split_content(game);

    for (int i = 0; game->map[i]; ++i) {
        printf("%s\n", game->map[i]);
    }
}
