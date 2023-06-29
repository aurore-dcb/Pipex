/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:51:17 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/29 12:16:49 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

int	loop_process(t_parsing *data, t_pid **pids, t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		data->middle_cmd = get_args(tmp->arg);
		if (data->middle_cmd == NULL)
		{
			ft_printf("Error -> Command\n");
			return (0);
		}
		data->middle_cmd_path = find_path(data->paths, data->middle_cmd[0]);
		if (!data->middle_cmd_path)
			return (0);
		if (!ft_process(data, pids, tmp))
			return (0);
		free_tab(data->middle_cmd);
		free(data->middle_cmd_path);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_process(t_parsing *data, t_pid **pids, t_cmd *cmd)
{
	pid_t	pid;

	if (!cmd || (cmd->next && pipe(data->fd) == -1))
		return (0);
	if (cmd->next && cmd->next->in == -2)
		cmd->next->in = data->fd[0];
	else if (cmd->next && cmd->next->in != -2)
		close(data->fd[0]);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		if (!ft_child(cmd, data))
			return (0);
	}
	else
	{
		ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
		if (data->fd[1] > 2)
			close(data->fd[1]);
		if (cmd->in > 2)
			close(cmd->in);
	}
	return (1);
}

int	ft_child(t_cmd *cmd, t_parsing *data)
{
	if (cmd->in > 2)
	{
		dup2(cmd->in, STDIN_FILENO);
		close(cmd->in);
	}
	if (cmd->next)
	{
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
	}
	else
	{
		dup2(data->outfile, STDOUT_FILENO);
		close(data->outfile);
	}
	if (execve(data->middle_cmd_path, data->middle_cmd, data->env) == -1)
		return (0);
	return (1);
}
