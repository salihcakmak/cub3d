#include "cub3d.h"

t_bool	ends_with(const	char *str, const char *suffix)
{
    t_uint	lenstr;
    t_uint	lensuffix;

    if (!str || !suffix)
        return (0);
    lenstr = my_strlen(str);
    lensuffix = my_strlen(suffix);
    if (lensuffix >= lenstr)
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

void	check_file_exist(const char *file)
{
    int	fd;

    fd = open(file, O_RDONLY);
    close(fd);
    if (fd < 0)
        message_with_exit(NULL, "No such file or directory");
}