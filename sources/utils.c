/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:14:06 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/28 17:30:10 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	parsing(int argc, char **argv, char **env, t_parsing *data)
{
	if (argc != 5)
		return (ft_printf("Error -> Wrong number of arguments\n"), 0);
	if (!env)
		return (ft_printf("Error -> No env\n"), 0);
	data->paths = get_paths(env);
	if (!data->paths)
		return (ft_printf("Error -> Paths\n"), 0);
	// data->first_cmd = get_args(argv[2]);
	// data->last_cmd = get_args(argv[argc - 2]);
	// if (!data->first_cmd || !data->last_cmd)
	// 	return (ft_printf("Error -> Command\n"), 0);
	// data->first_cmd_path = find_path(data->paths, data->first_cmd[0]);
	// data->last_cmd_path = find_path(data->paths, data->last_cmd[0]);
	// if (!data->first_cmd_path || !data->last_cmd_path)
	// 	return (ft_printf("Error -> Command\n"), 0);
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		return (ft_printf("Error -> Can't create/open file\n"), 0);
	data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0646);
	if (data->outfile == -1)
	{
		close(data->infile);
		return (ft_printf("Error -> Can't create/open file\n"), 0);
	}
	return (1);
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
