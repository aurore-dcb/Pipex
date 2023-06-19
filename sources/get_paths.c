#include "../libft/libft.h"
#include "../headers/pipex.h"

char *ft_trim(char *s)
{
    int i;
    char *res;

    i = 0;
    while (*s && i < 5)
    {
        ++s;
        i++;
    }
    res = ft_substr(s, 0, ft_strlen(s) - 5);
    return (res);
}

char **get_paths(char **env)
{
    int i;
    char *lign;
    char **paths;

    i = 0;
    if (!env)
        return (NULL);
    while (env[i])
    {
        if (ft_strnstr(env[i], "PATH=", 5))
        {
            lign = ft_trim(env[i]);
            if (!lign)
                return (0);
            paths = ft_split(lign, ':');
            free(lign);
            return (paths);
        }
        i++;
    }
    return (NULL);
}

char *find_path(char **paths)
{
    int i;

    i = 0;
    while (paths[i])
    {
        i++;
    }
}

void display_tab(char **tab)
{
    int i;

    i = 0;
    ft_printf("PATH=\n");
    while (tab[i])
    {
        ft_printf("%s\n", tab[i]);
        i++;
    }
}