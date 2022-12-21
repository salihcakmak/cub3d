#include "../header/cube.h"


int row_is_empty(char *s)
{
    while (*s)
    {
        if (*s != ' ' && *s != '\t' && *s != '\n')
            return TRUE;
        s++;
    }
    return FALSE;
}

int count_remaining_row(t_data *game, int  i)
{
    int count;
    count = 0;
    while (game->splited_content[i])
    {
        if (row_is_empty(game->splited_content[i]))
            count++;
        i++;
    }
    return count;
}


void    cut_content(t_data *game)
{
    int count;
    int i;
    int j;

    count = 0;
    i = 0;
    j = 0;
    game->config = calloc(sizeof(char *) , 7);
    while (game->splited_content[i] && count < 6)
    {
        if (row_is_empty(game->splited_content[i]))
        {
            game->config[j++] = game->splited_content[i];
            count++;
        }
        i++;
    }
    game->map = calloc(sizeof(char *), count_remaining_row(game, i));
    j = 0;
    while (game->splited_content[i])
    {
        if (row_is_empty(game->splited_content[i]))
            game->map[j++] = game->splited_content[i];
        i++;
    }
}

char	*ft_free_strjoin(char *dst, const char *src)
{
    int		i;
    char	*ret;

    if (!dst || !src)
        return (NULL);
    ret = malloc(sizeof(char) * (my_strlen(dst) + my_strlen(src) + 1));
    if (!ret)
        return (NULL);
    i = -1;
    while (dst[++i])
        ret[i] = dst[i];
    while (*src)
        ret[i++] = *src++;
    ret[i] = '\0';
    free(dst);
    return (ret);
}


char	*ft_str_clearspace(const char *str)
{
    int		i;
    int 	last_index;
    char 	*ret;
    char	*tmp;

    i = 0;
    last_index = 0;
    ret = ft_calloc(1, sizeof(char));
    while (str[i])
    {
        if (str[i] == ' ' || str[i + 1] == '\0')
        {
            tmp = ft_substr(str, last_index, (i - last_index) + 1);
            ret = ft_free_strjoin(ret,tmp);
            free(tmp);
            while (str[i] == ' ')
                i++;
            last_index = i;
        }
        i++;
    }
    return (ret);
}

char	*ft_strclear(char *str)
{
    char	*ret;
    char	*tmp;

    if (str == NULL)
        return (NULL);
    tmp = ft_strtrim(str, " ");
    ret = ft_str_clearspace(tmp);
    free(str);
    free(tmp);
    return (ret);
}

int	ft_getchr_index(const char *str, char c)
{
    int	i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    return (i);
}

int	parser_config_keyidx(const char *str, int len)
{
    static const char *keys[] = {"NO","SO","WE","EA","F","C"};
    int	i;

    i = 0;
    while (i < 6)
    {
        if (!ft_strncmp(str, keys[i], len))
            return (i);
        i++;
    }
    return (-1);
}


void    check_same_key(t_data *game)
{
    int i;
    int n;

    i = 0;
    while(i < 6)
    {
        n = -1;
        while(++n < 6)
        {
            if(n == i)
                continue;
            if(!ft_strncmp(game->keys[i],game->keys[n],ft_strlen(game->keys[i])))
                message_with_exit(game,"Error Same Key\n");
        }
        i++;
    }
}

void    check_value(t_data* game)
{
    int i;

    i = 0;
    while(i < 6)
    {
        if(!game->values[i] || !row_is_empty(game->values[i]))
            message_with_exit(game,"Error Invalid Value");
        i++;
    }
}

t_bool is_equal(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (FALSE);
        s1++;
        s2++;
    }
    return (TRUE);
}

void    check_config_name(t_data *game)
{
    static  char *cfg[7] = {"NO", "WE", "EA", "SO", "F", "C", 0};
    int j;
    int i;

    j = 0;
    while (cfg[j])
    {
        i = 0;
        while (i < 6)
        {
            if(is_equal(cfg[j], game->keys[i]))
                break;
            i++;
        }
        if (i == 6)
            message_with_exit(game, "Missing config value");
        j++;
    }
}


int ft_isnumeric(char *str)
{
    while(*str)
        if(!(*str++ >= '0' && *str <= '9'))
            return FALSE;
    return TRUE;
}

int     ft_doublefree(char **ptr)
{
    int i;

    i = 0;
    if(ptr)
    {
        while(ptr[i])
            free(ptr[i++]);
        free(ptr);
    }
    return 0;
}

int     check_color(char **colors)
{
    int i;
    int color;

    i = 0;
    while(i < 3)
    {
        if(!ft_isnumeric(colors[i]))
            return ft_doublefree(colors);
        color = ft_atoi(colors[i]);
        if(color < 0 || color > 255)
            return ft_doublefree(colors);
        i++;
    }
    return 1;
}

void    y(char **colors, unsigned char *ptr)
{
    int i;

    i = -1;
    while(colors[++i])
        ptr[i] = ft_atoi(colors[i]);
}

void    parse_rgb(t_data *game)
{
    int i;
    char **tmp;

    i = 0;
    while (i < 6)
    {
        if (is_equal(game->keys[i], "F"))
        {
            tmp = ft_split(game->values[i],',');
            if(!check_color(tmp))
                message_with_exit(game, "Error");
            y(tmp,game->f_rgb);
            ft_doublefree(tmp);
        }
        else if (is_equal(game->keys[i], "C"))
        {
            tmp = ft_split(game->values[i],',');
            if(!check_color(tmp))
                message_with_exit(game, "Error");
            y(tmp,game->c_rgb);
            ft_doublefree(tmp);
        }
        i++;
    }
}

void    x(t_data *game)
{
    int  i;

    i = 0;
    while (i < 6)
    {

        game->config[i] = ft_strclear(game->config[i]);
        char **data = ft_split(game->config[i], ' ');
        game->keys[i] = data[0];
        game->values[i] = data[1];
        i++;
    }
    check_same_key(game);
    check_value(game);
    check_config_name(game);
    parse_rgb(game);
}

void    init_axis(t_data *game)
{
    game->axis.right = 0;
    game->axis.left = 0;
    game->axis.top = 0;
    game->axis.top_left = 0;
    game->axis.top_right = 0;
    game->axis.bot = 0;
    game->axis.bot_left = 0;
    game->axis.bot_right = 0;
}

void set_axis(t_data *game, int row, int column)
{
    game->axis.top = column;
    game->axis.bot = column;
    game->axis.left = column - 1;
    game->axis.right = column + 1;

}

void check_map(t_data *game)
{
    ft_memset(&game->axis,0,sizeof(t_axis))
    init_axis(game);
    while ()
}

void	initialize_data_object(t_data *game, const char *f_path)
{
    game->f_path = f_path;
    game->f_size = get_file_len(game);
    game->f_content = get_file_content(game);
    game->f_row_count = get_row_count(game);
    set_split_content(game);
    cut_content(game);
    x(game);
    check_map(game);

}









