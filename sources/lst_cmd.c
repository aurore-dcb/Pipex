/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:19:02 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/28 11:20:30 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

t_cmd	*ft_lstnew_cmd(char *arg)
{
	t_cmd	*elem;

	elem = malloc(sizeof(t_cmd));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->in = -2;
	elem->arg = ft_strdup(arg);
	if (!elem->arg)
		return (NULL);
	return (elem);
}

int	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*list;

	if (!new)
		return (0);
	list = *lst;
	if (list && new)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*lst = new;
	return (1);
}

int	create_list_cmd(t_cmd **cmd, int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc - 1)
	{
		if (!ft_lstadd_back_cmd(cmd, ft_lstnew_cmd(argv[i])))
			return (ft_printf("Error -> list commande\n"), 0);
		i++;
	}
	return (1);
}
