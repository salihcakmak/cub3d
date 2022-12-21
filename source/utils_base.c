#include "../header/cube.h"

void	clear_memory(t_data *game)
{
    //TODO
}

void	message_with_exit(t_data *game, const char *message)
{
    clear_memory(game);
    printf("Error\n%s\n", message);
    exit(1);
}