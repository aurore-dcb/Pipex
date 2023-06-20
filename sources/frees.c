#include "../libft/libft.h"
#include "../headers/pipex.h"

void free_path(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}