#include "../header/cube.h"

t_uint	my_strlen(const char *str)
{
    t_uint	len;

    len = 0;
    while (str && *str++)
        len++;
    return (len);
}

t_bool contains(char c, char *set)
{
    printf("%c", c);
    if ((c >= 9 && c < 13) || c == 32)
        return (TRUE);
    while (*set)
        if (*set++ == c)
            return (TRUE);
    return (FALSE);
}

char	*substr(char const *s, unsigned int start, size_t len)
{
    char	*substr;
    size_t	i;

    if (!s)
        return (NULL);
    if (my_strlen(s) < len)
        len = my_strlen(s);
    if (my_strlen(s) < start)
        return (0);
    substr = (char *)malloc(sizeof(char) * len + 1);
    if (!substr)
        return (0);
    i = 0;
    while (i < len && s[i])
    {
        substr[i] = s[i + start];
        i++;
    }
    substr[i] = 0;
    return (substr);
}