/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:42:19 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 14:31:33 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int parsing(int argc, char **argv, char **env, t_parsing *data)
{
    if (argc != 5)
		return (ft_printf("Error\nWrong number of arguments\n"), 1);
	if (!env)
		return (ft_printf("No env\n"), 0);
    data->paths = get_paths(env);
    if (!data->paths)
        return (ft_printf("Error\nPaths\n"), 0);
    data->cmd1 = get_args(argv[2]);
    data->cmd2 = get_args(argv[3]);
    if (!data->cmd1 || !data->cmd2)
        return (ft_printf("Error\nCommand\n"), 0);
}

t_pid	*ft_lstnew_pipex(pid_t pid)
{
	t_pid	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->pid = pid;
	return (elem);
}

void	ft_lstadd_back_pipex(t_pid **lst, t_pid *new)
{
	t_pid	*list;

	list = *lst;
	if (list && new)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*lst = new;
}

