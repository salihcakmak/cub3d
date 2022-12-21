#include "../header/cube.h"

int get_file_len(t_data *game)
{
    int count;
    int fd;

    count = 0;
    fd = open(game->f_path, O_RDONLY);
    if (fd < 0)
        message_with_exit(game, "No such file or directory");
    while (read(fd, &(char){0}, 1) > 0)
        count++;
    close(fd);
    return (count);
}

char	*get_file_content(t_data *game)
{
    int     fd;
    char    *content;

    content = malloc(sizeof(char) * game->f_size + 1);
    if (!content)
        message_with_exit(game,"Memory was not allocated for read content");
    fd = open(game->f_path, O_RDONLY);
    if (fd < 0)
        message_with_exit(game, "No such file or directory");
    if (game->f_size != read(fd, content, game->f_size))
        message_with_exit(game, "Content could not be read completely");
    close(fd);
    content[game->f_size] = 0;
    return (content);
}

t_uint  get_row_count(t_data *game)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (game->f_content[i])
    {
        while (game->f_content[i] != '\n' && game->f_content[i] != '\0')
            i++;
        if (game->f_content[i] == '\n' || game->f_content[i] == '\0')
            count++;
        if (game->f_content[i] != '\0')
            i++;
    }
    return (count);
}

void    set_split_content(t_data *game)
{
    int i;
    int end;
    int map_i;

    game->splited_content = malloc(sizeof(char *) * (game->f_row_count + 1));
    if (!game->splited_content)
        message_with_exit(game, "Map memory was not allocated.");
    i = 0;
    end = 0;
    map_i = 0;
    while (game->f_content[i])
    {
        if(game->f_content[i] == '\n')
        {
            game->splited_content[map_i++] = substr(game->f_content, end, i - end);
            end = i + 1;
        }
        else if (game->f_content[i + 1] == '\0'){
            game->splited_content[map_i++] = substr(game->f_content, end, i + 1);
        }
        i++;
    }
    game->splited_content[map_i] = 0;
}