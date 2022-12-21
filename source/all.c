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

#include "../header/cube.h"

void	check_game_status(t_data *game)
{

	//TODO
	// check all case, if code block is here. Game must be end.
}

void    check_possible_character(t_data *game)
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

