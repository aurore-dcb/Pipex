/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 11:20:53 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"

int main(int argc, char **argv, char **env)
{
    pid_t pid;
    char *cmd; // free
    char **paths; // free
    int const READ_END = 0;
    int const WRITE_END = 1;
    int pdes[2];

    pipe(pdes);
    (void)argc;
    (void)argv;
    // if (argc != 5)
        // return (ft_printf("Error\nWrong number of arguments\n"), 1);
    if (!env)
        return (ft_printf("No env\n"), 0);
    int fd = open("file_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (ft_printf("Error\nCan't create/open file\n"), 1);
    pid = fork();
    if (pid == 0) //child
    {
        paths = get_paths(env);
        if (!paths)
            return (ft_printf("Error\nPaths null\n"), 1);
        cmd = find_path(paths, "ls");
        if (!cmd)
            return (ft_printf("Error\nCan't find cmd\n"), 1);
        dup2(pdes[WRITE_END], STDOUT_FILENO);
        close(pdes[READ_END]);
        execve(cmd, argv, env);
        free(cmd);
        free_path(paths);
    }
    else //parent
    {
        dup2(pdes[READ_END], STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        close(pdes[WRITE_END]);
        wait(NULL);
        execve("/bin/cat", argv, env);
    }
}