/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:00:17 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 13:52:59 by aducobu          ###   ########.fr       */
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
    count = 0;
    cmd = malloc(sizeof(char) * (count + 1));
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

char *ft_trim2(char *s)
{
    int i;
    char *res;

    i = 0;
    while (*s && *s == ' ')
	{
		++s;
		i++;
	}
    while (*s && *s != ' ')
	{
		++s;
		i++;
	}
    while (*s && *s == ' ')
        ++s;
    while (*(s + i))
    {
        i++;
    }
    res = ft_substr(s, 0, i);
    return (res);
}

char **get_args(char *cmd)
{
    
}