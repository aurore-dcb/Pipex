/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:51:17 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/28 10:47:24 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

int	loop_process(t_parsing *data, t_pid **pids, t_cmd **cmd)
{
    t_cmd *tmp;
    
    tmp = *cmd;
	while (tmp)
	{
		ft_printf("test = %s.\n", tmp->arg);
		if (!ft_process(data, pids, tmp))
            return (0);
        tmp = tmp->next;
	}
	//fct wait pid
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
    data->middle_cmd = get_args(cmd->arg);
	if (data->middle_cmd == NULL)
	{
		ft_printf("Error -> Command\n");
		return (0);
	}
	data->middle_cmd_path = find_path(data->paths, data->middle_cmd[0]);
	if (!data->middle_cmd_path)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	// exit_child(lst_cmd, lst_pid, "pid ");
	if (pid == 0)
	{
		// ft_signal(CHILD);
		if (!ft_child(cmd, pids, data))
            return (0);
	}
	else
	{
		// ft_signal(IGNORE);
		ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
		if (data->fd[1] > 2)
			close(data->fd[1]);
		if (cmd->in > 2)
			close(cmd->in);
	}
    return (1);
}

int	ft_child(t_cmd *cmd, t_pid **pids, t_parsing *data)
{
    (void)pids;
	// if (cmd->in == -1)
	// {
	// 	errno = 1;
	// 	exit_child(lst_cmd, lst_pid, "main");
	// }
	if (cmd->in > 2)
	{
		dup2(cmd->in, STDIN_FILENO);
		close(cmd->in);
	}
	// if (cmd->out > 2)
	// {
	// 	dup2(cmd->out, STDOUT_FILENO);
	// 	close(cmd->out);
	// }
	if (cmd->next)
	{
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
	}
	if (!ft_exec(data))
		return (0);
	// exit_child(lst_cmd, lst_pid, "main");
    return (1);
}

int	ft_exec(t_parsing *data)
{
	if (execve(data->middle_cmd_path, data->middle_cmd, data->env) == -1)
        return (0);
    return (1);
	// perror("Error while command execution");
}
