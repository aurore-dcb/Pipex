/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 13:52:37 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"


// int main(int argc, char **argv, char **env)
// {
//     pid_t pid;
//     char *cmd; // free
//     char **paths; // free
//     int const READ_END = 0;
//     int const WRITE_END = 1;
//     int pdes[2];
//     int outfile;
//     int infile;
    
//     char *arg1[3];
//     char *cmd1 = NULL;
//     cmd1 = get_cmd(argv[2]);
//     arg1[0] = "-l";
//     arg1[1] = "-a";
//     arg1[2] = NULL;

//     char *arg2[3];
//     char *cmd2 = NULL;
//     cmd2 = get_cmd(argv[3]);
//     arg2[0] = cmd2;
//     arg2[1] = "-l";
//     arg2[2] = NULL;
    
//     ft_printf("cmd1 =%s\n", cmd1);
//     ft_printf("cmd2 =%s\n", cmd2);
//     (void)argc;
//     (void)argv;
//     if (argc != 5)
//         return (ft_printf("Error\nWrong number of arguments\n"), 1);
//     if (!env)
//         return (ft_printf("No env\n"), 0);
//     pipe(pdes);
//     outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (outfile == -1)
//         return (ft_printf("Error\nCan't create/open file\n"), 1);
//     infile = open(argv[1], O_RDONLY);
//     if (infile == -1)
//         return (ft_printf("Error\nCan't create/open file\n"), 1);
//     pid = fork();
//     if (pid == 0) //child
//     {
//         paths = get_paths(env);
//         if (!paths)
//             return (ft_printf("Error\nPaths null\n"), 1);
//         cmd = find_path(paths, "ls");
//         if (!cmd)
//             return (ft_printf("Error\nCan't find cmd\n"), 1);
//         dup2(infile, STDIN_FILENO);
//         dup2(pdes[WRITE_END], STDOUT_FILENO);
//         close(pdes[READ_END]);
//         execve(cmd1, arg1, env);
//         free(cmd);
//         free_path(paths);
//     }
//     else //parent
//     {
//         dup2(pdes[READ_END], STDIN_FILENO);
//         dup2(outfile, STDOUT_FILENO);
//         close(pdes[WRITE_END]);
//         wait(NULL);
//         execve(cmd2, arg2, env);
//     }
// }



int main()
{
    ft_printf("cmd = %s.\n", ft_trim2("ls   -l    -a"));
}
