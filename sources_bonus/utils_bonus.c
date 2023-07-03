/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:14:06 by aducobu           #+#    #+#             */
/*   Updated: 2023/07/03 10:34:10 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

int	parsing(int argc, char **argv, char **env, t_parsing *data)
{
	if (argc < 5)
		return (ft_printf("Error -> Wrong number of arguments\n"), 0);
	if (!env)
		return (ft_printf("Error -> No env\n"), 0);
	data->paths = get_paths(env);
	if (!data->paths)
		return (ft_printf("Error -> Paths\n"), 0);
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		return (ft_printf("Error -> Can't create/open file\n"), 0);
	data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0646);
	if (data->outfile == -1)
	{
		close(data->infile);
		ft_printf("Error -> Can't create/open file\n");
		return (0);
	}
	return (1);
}

t_pid	*ft_lstnew_pipex(pid_t pid)
{
	t_pid	*elem;

	elem = malloc(sizeof(t_pid));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->pid = pid;
	return (elem);
}

int	ft_lstadd_back_pipex(t_pid **lst, t_pid *new)
{
	t_pid	*list;

	list = *lst;
	if (!new)
		return (0);
	if (list && new)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
	{
		*lst = new;
	}
	return (1);
}
