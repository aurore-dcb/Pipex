/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:48:02 by aducobu           #+#    #+#             */
/*   Updated: 2023/07/03 10:59:16 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	free_pids(t_pid **pids)
{
	t_pid	*tmp;

	while (*pids)
	{
		tmp = *pids;
		*pids = (*pids)->next;
		free(tmp);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	t_cmd	*temp;

	if (!lst)
		return ;
	temp = NULL;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->arg);
		free(temp);
	}
}
