/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:11:36 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/27 09:37:32 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	first_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		return (ft_printf("Error -> Pipe\n"), 0);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(data->infile, STDIN_FILENO) == -1 || dup2(data->fd[1],
				STDOUT_FILENO) == -1 || close(data->fd[0]) == -1
			|| close(data->fd[1]) == -1)
			return (0);
		execve(data->first_cmd_path, data->first_cmd, data->env);
		perror("Error while command execution");
	}
	util(data, pids, pid);
	return (1);
}

int	util(t_parsing *data, t_pid **pids, pid_t pid)
{
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
	if (dup2(data->fd[0], STDIN_FILENO) == -1 || close(data->fd[1]) == -1
		|| close(data->fd[0]) == -1)
		return (0);
	return (1);
}
