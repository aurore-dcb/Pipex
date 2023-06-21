/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:43:21 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 15:47:34 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	last_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[1]);
		dup2(data->outfile, STDOUT_FILENO);
		// close(outfile);
		execve(data->last_cmd_path, data->last_cmd, data->env);
		perror("Error while command execution");
	}
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
}
