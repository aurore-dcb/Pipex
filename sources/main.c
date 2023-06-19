/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/19 13:53:52 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"

int main(int argc, char **argv, char **env)
{
    pid_t pid;
    char **paths;

    (void)argc;
    // if (argc != 5)
        // return (ft_printf("Error\nWrong number of arguments\n"), 1);
    if (!env)
        return (ft_printf("No env\n"), 0);
    pid = fork();
    if (pid == 0)
    {
        ft_printf("Je suis l'enfant.\n");
        paths = get_paths(env); // a free
        if (!paths)
            return (ft_printf("Error\nPaths null\n"), 1);
        display_tab(paths);
        execve("/bin/ls", argv, env);
    }
    else
    {
        ft_printf("Je suis le parent.\n");
    }
}