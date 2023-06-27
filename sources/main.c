/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:13:20 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/27 09:13:36 by aducobu          ###   ########.fr       */
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
	data->middle_cmd = NULL;
	data->middle_cmd_path = NULL;
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
	if (!first_process(&data, &pids) || !middle(&data, &pids)
		|| !last_process(&data, &pids))
	{
		free_all(&data);
		return (1);
	}
	wait_fct(&pids, &data);
}
