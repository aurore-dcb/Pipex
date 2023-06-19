/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/19 12:30:36 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int main(int argc, char **argv, char **env)
{
    pid_t pid;

    (void)argc;
    (void)argv;
    // if (argc != 5)
        // return (ft_printf("Error\nWrong number of arguments\n"), 1);
    if (!env)
        return (ft_printf("No env\n"), 0);
    pid = fork();
    // ft_printf("pid = %d\n", pid);
    if (pid == 0)
    {
        ft_printf("Je suis l'enfant.\n");
    }
    else
    {
        ft_printf("Je suis le parent.\n");
    }
}