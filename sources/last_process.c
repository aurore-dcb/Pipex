/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:43:21 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/26 09:38:38 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	last_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		return (ft_printf("Error pipe\n"), 0);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(data->outfile, STDOUT_FILENO) == -1 || close(data->fd[0]) == -1
			|| close(data->fd[1]) == -1)
			return (0);
		execve(data->last_cmd_path, data->last_cmd, data->env);
		perror("Error while command execution");
	}
	util(data, pids, pid);
	return (1);
}
