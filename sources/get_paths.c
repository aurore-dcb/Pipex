/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:28:24 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 15:49:36 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

char	*ft_trim(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (*s && i < 5)
	{
		++s;
		i++;
	}
	res = ft_substr(s, 0, ft_strlen(s) - 5);
	return (res);
}

char	**get_paths(char **env)
{
	int		i;
	char	*lign;
	char	**paths;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			lign = ft_trim(env[i]);
			if (!lign)
				return (0);
			paths = ft_split(lign, ':');
			free(lign);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*slash;
	char	*all_path;

	i = 0;
	while (paths[i])
	{
		slash = ft_strjoin(paths[i], "/");
		if (!slash)
			return (NULL);
		all_path = ft_strjoin(slash, cmd);
		free(slash);
		if (!all_path)
			return (NULL);
		if (access(all_path, F_OK | R_OK | X_OK) == 0)
			return (all_path);
		i++;
		free(all_path);
	}
	return (NULL);
}

void	display_tab(char **tab)
{
	int	i;

	i = 0;
	ft_printf("PATH=\n");
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
