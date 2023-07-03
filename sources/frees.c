/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:11:55 by aducobu           #+#    #+#             */
/*   Updated: 2023/07/03 10:46:39 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	error_free(t_parsing *data, t_cmd **cmd, t_pid **pids)
{
	free_pids(pids);
	if (data->fd[0] > 1)
		close(data->fd[0]);
	if (data->fd[1] > 1)
		close(data->fd[1]);
	if (data->paths)
		free_tab(data->paths);
	if (data->middle_cmd)
		free_tab(data->middle_cmd);
	if (data->middle_cmd_path)
		free(data->middle_cmd_path);
	if (cmd)
		ft_lstclear_cmd(cmd);
	if (data->infile > 1)
		close(data->infile);
	if (data->outfile > 1)
		close(data->outfile);
}

void	free_all(t_parsing *data, t_cmd **cmd)
{
	if (data->infile > 1)
		close(data->infile);
	if (data->outfile > 1)
		close(data->outfile);
	if (data->paths)
		free_tab(data->paths);
	if (cmd)
		ft_lstclear_cmd(cmd);
}

void	wait_fct(t_pid **pids, t_parsing *data, t_cmd **cmd)
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
	free_all(data, cmd);
}
