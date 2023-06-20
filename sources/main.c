/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 16:00:13 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	char	**paths;
	int		fd[2];
	int		outfile;

	if (argc != 5)
		return (ft_printf("Error\nWrong number of arguments\n"), 1);
	if (!env)
		return (ft_printf("No env\n"), 0);
	pipe(fd);
	paths = get_paths(env);
	if (!paths)
		return (ft_printf("Error\nPaths null\n"), 1);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (ft_printf("Error\nCan't create/open file\n"), 1);
	pid = fork();
	if (pid == 0) //child
		process_child(fd, argv, env, paths);
	else //parent
		process_parrent(fd, argv, env, paths, pid);
}
