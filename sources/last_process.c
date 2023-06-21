/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:43:21 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 14:37:45 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	last_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;
	int		outfile;
	char	*cmd_path;

	pid = fork();
	if (pid == 0)
	{
		outfile = open(data->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 777);
		if (outfile == -1)
			return (ft_printf("Error\nCan't create/open file\n"), 1);
		cmd_path = find_path(data->paths, data->cmd2[0]);
			// tester si la commande (2e arg) existe et recuperer le chemin absolu
		if (!cmd_path)
			return (ft_printf("Error\nCan't find cmd\n"), 1);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[1]);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		execve(cmd_path, data->cmd2, data->env);
		perror("Erreur lors de l'exécution de la commande");
	}
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
}
