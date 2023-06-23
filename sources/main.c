/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/23 11:19:51 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	initialise(t_parsing *data)
{
	data->paths = NULL;
	data->first_cmd = NULL;
	data->last_cmd = NULL;
	data->first_cmd_path = NULL;
	data->last_cmd_path = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_parsing	data;
	t_pid		*pids;

	data.argc = argc;
	data.argv = argv;
	data.env = env;
	initialise(&data);
	if (!parsing(argc, argv, env, &data))
		return (error_free(&data), 1);
	pids = NULL;
	if (pipe(data.fd) == -1)
	{
		ft_printf("Error\n");
		return (free_all(&data));
	}
	if (!first_process(&data, &pids) || !last_process(&data, &pids))
	{
		ft_printf("Error\n");
		return (free_all(&data));
	}
	wait_fct(&pids, &data);
}
