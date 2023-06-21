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

void wait_fct(t_pid **pids)
{
	t_pid *tmp;

	while (*pids)
	{
		tmp = *pids;
		waitpid(((*pids)->pid), NULL, 0);
		*pids = (*pids)->next;
		free(tmp);
	}
	free(*pids);
}

