/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:07:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 16:05:12 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	process_child(int *fd, char **argv, char **env, char **paths)
{
	int		infile;
	char	*cmd;
	char	*cmd_path;
	char	**args;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (ft_printf("Error\nCan't create/open file\n"), 1);
	cmd = get_cmd(argv[2]);
	if (!cmd)
		return (0);
	cmd_path = find_path(paths, cmd);// tester si la commande (2e arg) existe et recuperer le chemin absolu
	if (!cmd_path)
		return (ft_printf("Error\nCan't find cmd\n"), 1);
	args = get_args(argv[2]);
	if (!args)
		return (ft_printf("Error\nARGS\n"), 0);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execve(cmd_path, args, env);
	return (1);
}
