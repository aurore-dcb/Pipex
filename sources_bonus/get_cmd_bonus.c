/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:12:22 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/27 09:53:13 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

char	*get_cmd(char *s)
{
	int		i;
	int		count;
	char	*cmd;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i++] != ' ')
		count++;
	cmd = malloc(sizeof(char) * (count + 1));
	if (!cmd)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] != ' ')
		cmd[count++] = s[i++];
	cmd[i] = 0;
	return (cmd);
}

char	**get_args(char *cmd)
{
	char	**args;

	if (!cmd)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	return (args);
}
