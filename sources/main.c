/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/23 09:24:22 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **env)
{
	t_parsing	data;
	t_pid		*pids;

	if (!parsing(argc, argv, env, &data))
		return (1);
	pids = NULL;
	data.argc = argc;
	data.argv = argv;
	data.env = env;
	if (pipe(data.fd) == -1)
	{
		ft_printf("Error\n");
		return (free_all(&data));
	}
	if (!first_process(&data, &pids))
	{
		ft_printf("Error\n");
		return (free_all(&data));
	}
	if (!last_process(&data, &pids))
	{
		ft_printf("Error\n");
		return (free_all(&data));
	}
	wait_fct(&pids, &data);
}
