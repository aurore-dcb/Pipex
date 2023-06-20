/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 15:52:58 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"



int main(int argc, char **argv, char **env)
{
    pid_t pid;
    char **paths;
    int const READ_END = 0;
    int const WRITE_END = 1;
    int fd[2];
    int outfile;

    if (argc != 5)
        return (ft_printf("Error\nWrong number of arguments\n"), 1);
    if (!env)
        return (ft_printf("No env\n"), 0);

    
    
    (void)argc;
    (void)argv;
    
    pipe(fd);
    paths = get_paths(env);
    if (!paths)
        return (ft_printf("Error\nPaths null\n"), 1);
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile == -1)
        return (ft_printf("Error\nCan't create/open file\n"), 1);
    pid = fork();
    if (pid == 0) //child
    {
        process_child(fd, argv, env);
    }
    else //parent
    {
        process_parrent(fd, argv, env, paths, pid);
    }
}



// int main(int argc, char **argv, char **env)
// {
//     char **paths;
//     (void)argc;
//     (void)argv;
//     paths = get_paths(env);
//     ft_printf("%s\n", find_path(paths, "ls -l"));
// }
