/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:12:58 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/28 11:36:41 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	last_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		return (ft_printf("Error -> pipe\n"), 0);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(data->fd[0], STDIN_FILENO) == -1 || dup2(data->outfile, STDOUT_FILENO) ||
			close(data->fd[0]) == -1 || close(data->outfile))
			return (0);
		execve(data->last_cmd_path, data->last_cmd, data->env);
		perror("Error while command execution");
	}
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
	// util(data, pids, pid);
	return (1);
}
