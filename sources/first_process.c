/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:07:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/23 15:00:02 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	first_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;

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
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
	return (1);
}
