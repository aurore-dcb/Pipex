/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:43:21 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 15:52:25 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"

int process_parrent(int *fd, char **argv, char **env, char **paths, int pid)
{
    
    char *cmd2 = NULL;
    cmd2 = get_cmd(argv[3]);
    char *cmd;
    cmd = find_path(paths, cmd2); // tester si la commande (2e arg) existe et recuperer le chemin absolu
    if (!cmd)
        return (ft_printf("Error\nCan't find cmd\n"), 1);
    char **args;
    args = get_args(argv[3]);
    if (!args)
        return (ft_printf("Error\nARGS\n"), 0);
    dup2(fd[0], STDIN_FILENO);
    dup2(STDOUT_FILENO, fd[1]);
    close(fd[1]);
    waitpid(pid, NULL, 0);
    execve(cmd, args, env);
}
