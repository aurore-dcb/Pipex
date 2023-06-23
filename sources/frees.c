/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:50:02 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/23 09:25:09 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	free_path(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	wait_fct(t_pid **pids, t_parsing *data)
{
	t_pid	*tmp;
	close(data->fd[0]);
	close(data->fd[1]);
	while (*pids)
	{
		tmp = *pids;
		waitpid(((*pids)->pid), NULL, 0);
		*pids = (*pids)->next;
		free(tmp);
	}
	free(*pids);
	free_all(data);
}

int	free_all(t_parsing *data)
{
	close(data->infile);
	close(data->outfile);
	free_path(data->paths);
	free_path(data->first_cmd);
	free_path(data->last_cmd);
	free(data->first_cmd_path);
	free(data->last_cmd_path);
	return (1);
}