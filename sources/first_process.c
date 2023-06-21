/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:07:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 15:36:13 by aducobu          ###   ########.fr       */
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
		dup2(data->infile, STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		execve(data->first_cmd_path, data->first_cmd, data->env);
		perror("Error while command execution");
	}
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
}
