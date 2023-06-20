/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:43:21 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 16:07:05 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	process_parrent(int *fd, char **argv, char **env, char **paths, int pid)
{
	char	*cmd;
	char	*cmd_path;
	char	**args;

	cmd = get_cmd(argv[3]);
	cmd_path = find_path(paths, cmd);// tester si la commande (2e arg) existe et recuperer le chemin absolu
	if (!cmd_path)
		return (ft_printf("Error\nCan't find cmd\n"), 1);
	args = get_args(argv[3]);
	if (!args)
		return (ft_printf("Error\nARGS\n"), 0);
	dup2(fd[0], STDIN_FILENO);
	dup2(STDOUT_FILENO, fd[1]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	execve(cmd_path, args, env);
}
