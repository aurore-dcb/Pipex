/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:11:55 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/27 11:06:56 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	error_free(t_parsing *data)
{
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

void	free_all(t_parsing *data)
{
	close(data->infile);
	close(data->outfile);
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
