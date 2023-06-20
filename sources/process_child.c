/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:07:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 15:52:36 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"

int process_child(int *fd, char **argv, char **env)
{
    int infile;
    char **paths;
    char *cmd;
    char *cmd1;
    char **args;
    
    paths = get_paths(env);
    if (!paths)
        return (ft_printf("Error\nPaths null\n"), 1);
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
        return (ft_printf("Error\nCan't create/open file\n"), 1);
    cmd1 = get_cmd(argv[2]);
    if (!cmd1)
        return (0);
    cmd = find_path(paths, cmd1); // tester si la commande (2e arg) existe et recuperer le chemin absolu
    if (!cmd)
        return (ft_printf("Error\nCan't find cmd\n"), 1);
    args = get_args(argv[2]);
    if (!args)
        return (ft_printf("Error\nARGS\n"), 0);
    dup2(infile, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    execve(cmd, args, env);
    return (1);
}
