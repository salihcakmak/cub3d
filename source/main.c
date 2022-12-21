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

#include "../header/cube.h"


int	main(int argc, char const *argv[])
{

	t_data	game;

    if (argc != 2)
        message_with_exit(NULL, "To many arguments!");
    if (!ends_with(argv[1], ".cub"))
        message_with_exit(NULL, "Unsupported file extension!");
    check_file_exist(argv[1]);
    initialize_data_object(&game, argv[1]);

	return (0);
}
