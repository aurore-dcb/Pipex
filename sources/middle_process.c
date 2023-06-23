/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/23 15:07:39 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

// int	first_process(t_parsing *data, t_pid **pids)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (dup2(data->infile, STDIN_FILENO) == -1 || dup2(data->fd[1],
// 				STDOUT_FILENO) == -1 || close(data->fd[0]) == -1
// 			|| close(data->fd[1]) == -1)
// 			return (0);
// 		execve(data->first_cmd_path, data->first_cmd, data->env);
// 		perror("Error while command execution");
// 	}
// 	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
// 	return (1);
// }

int	middle_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;
    int pipe_fd[2];
    
	while (data->index < data->argc - 2)
	{
        ft_printf("data->index = %d\n", data->index);
        pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			if (dup2(data->fd[0], STDIN_FILENO) == -1 || dup2(data->fd[1],
					STDOUT_FILENO) == -1 || close(data->fd[1]) == -1
				|| close(data->fd[0]) == -1)
				return (0);
			data->middle_cmd_path = find_path(data->paths, data->middle_cmd[0]);
			if (!data->middle_cmd_path)
				return (ft_printf("error\n"), 0);
			data->middle_cmd = get_args(data->argv[data->index]);
			if (!data->middle_cmd)
				return (ft_printf("la\n"), 0);
            // printf("data->middle_cmd[0] = %s\n", data->middle_cmd[0]);
			execve(data->middle_cmd_path, data->middle_cmd, data->env);
			perror("Error while command execution");
		}
        close(data->fd[0]); // Fermer l'extrémité inutilisée du tube
		close(data->fd[1]);
		data->fd[0] = pipe_fd[0]; // Mettre à jour le descripteur de fichier d'entrée pour le prochain processus
		data->fd[1] = pipe_fd[1]; 
		ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
	    data->index++;
	}
	return (1);
}
// int	last_process(t_parsing *data, t_pid **pids)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (dup2(data->fd[0], STDIN_FILENO) == -1 || dup2(data->outfile,
// 				STDOUT_FILENO) == -1 || close(data->fd[1]) == -1
// 			|| close(data->fd[0]) == -1)
// 			return (0);
// 		execve(data->last_cmd_path, data->last_cmd, data->env);
// 		perror("Error while command execution");
// 	}
// 	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
// 	return (1);
// }