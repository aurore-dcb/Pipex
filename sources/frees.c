/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:50:02 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/26 10:25:05 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	error_free(t_parsing *data)
{
	ft_printf("Error\n");
	if (data->paths)
		free_tab(data->paths);
	if (data->first_cmd)
		free_tab(data->first_cmd);
	if (data->last_cmd)
		free_tab(data->last_cmd);
	if (data->first_cmd_path)
		free(data->first_cmd_path);
	if (data->last_cmd_path)
		free(data->last_cmd_path);
}

void	free_tab(char **tab)
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
	int		i;

	i = 0;
	close(data->fd[0]);
	close(data->fd[1]);
	while (*pids)
	{
		tmp = *pids;
		waitpid(((*pids)->pid), NULL, 0);
		*pids = (*pids)->next;
		free(tmp);
		i++;
	}
	free(*pids);
	free_all(data);
}

void	free_all(t_parsing *data)
{
	close(data->infile);
	close(data->outfile);
	free_tab(data->paths);
	free_tab(data->first_cmd);
	free_tab(data->last_cmd);
	free(data->first_cmd_path);
	free(data->last_cmd_path);
}
