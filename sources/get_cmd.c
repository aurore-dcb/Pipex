/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:00:17 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 11:15:47 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/pipex.h"

char *get_cmd(char *s)
{
    int i;
    int count;
    char *cmd;

    i = 0;
    count = 0;
    if (!s)
        return (NULL);
    while (s[i] && s[i] == ' ')
        i++;
    while (s[i] && s[i++] != ' ')
        count++;
    i = 0;
    cmd = malloc(sizeof(char) * (count + 1));
    count = 0;
    while (s[i] && s[i] == ' ')
        i++;
    while (s[i] && s[i] != ' ')
    {
        cmd[count] = s[i];
        count++;
        i++;
    }
    cmd[i] = 0;
    return (cmd);
}

char **get_args(char *cmd)
{
    char **args;
    
    args = ft_split(cmd, ' ');
    if (!args)
    {
        free_path(args);
        return (NULL);
    }
    return (args);
}
