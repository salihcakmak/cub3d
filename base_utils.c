#include "cub3d.h"

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