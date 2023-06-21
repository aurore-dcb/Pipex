/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:07:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 14:37:35 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	first_process(t_parsing *data, t_pid **pids)
{
	int		infile;
	char	*cmd_path;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		infile = open(data->argv[1], O_RDONLY);
		if (infile == -1)
			return (ft_printf("Error\nCan't create/open file\n"), 1);
		cmd_path = find_path(data->paths, data->cmd1[0]);// tester si la commande (2e arg) existe et recuperer le chemin absolu
		if (!cmd_path)
			return (ft_printf("Error\nCan't find cmd\n"), 1);
		dup2(infile, STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		execve(cmd_path, data->cmd1, data->env);
		perror("Erreur lors de l'exécution de la commande");
	}
	ft_lstadd_back_pipex(pids, ft_lstnew_pipex(pid));
}
