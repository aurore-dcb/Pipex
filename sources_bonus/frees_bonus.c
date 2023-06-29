/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:11:55 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/29 14:57:26 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

void	error_free(t_parsing *data, t_cmd **cmd)
{
	if (data->paths)
		free_tab(data->paths);
	if (data->middle_cmd)
		free_tab(data->middle_cmd);
	if (data->middle_cmd_path)
		free(data->middle_cmd_path);
	if (cmd)
		ft_lstclear_cmd(cmd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	wait_fct(t_pid **pids, t_parsing *data, t_cmd **cmd)
{
	t_pid	*tmp;

	close(data->fd[0]);
	close(data->fd[1]);
	while (*pids)
	{
		tmp = *pids;
		waitpid(((*pids)->pid), NULL, 0);
		*pids = (*pids)->next;
		free(tmp);
	}
	free(*pids);
	free_all(data, cmd);
}

void	free_all(t_parsing *data, t_cmd **cmd)
{
	if (data->infile > 1)
		close(data->infile);
	if (data->outfile > 1)
		close(data->outfile);
	if (data->paths)
		free_tab(data->paths);
	ft_lstclear_cmd(cmd);
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	t_cmd	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->arg);
		free(temp);
	}
	temp = NULL;
}
