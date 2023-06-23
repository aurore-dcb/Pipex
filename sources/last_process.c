/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:43:21 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/23 15:05:17 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	last_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;
	int pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(data->fd[0], STDIN_FILENO) == -1 || dup2(data->outfile,
				STDOUT_FILENO) == -1 || close(data->fd[1]) == -1
			|| close(data->fd[0]) == -1)
			return (0);
		execve(data->last_cmd_path, data->last_cmd, data->env);
		perror("Error while command execution");
	}
	// close(data->fd[0]); // Fermer l'extrémité inutilisée du tube
	// close(data->fd[1]);
	// data->fd[0] = pipe_fd[0]; // Mettre à jour le descripteur de fichier d'entrée pour le prochain processus
	// data->fd[1] = pipe_fd[1]; 
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
	return (1);
}
