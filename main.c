/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:26:09 by scakmak           #+#    #+#             */
/*   Updated: 2022/10/23 11:59:40 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char const *argv[])
{
	t_cub3d	game;

    if (argc != 2)
        message_with_exit(NULL, "To many arguments!");

    check_file_exist(argv[1]);
    if (!ends_with(argv[1], ".cub"))
        message_with_exit(NULL, "Unsupported file extension!");
    game.f_name = argv[1];
    initialize_cub3d_object(&game);
	return (0);
}
