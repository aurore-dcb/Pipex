/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:13:20 by aducobu           #+#    #+#             */
/*   Updated: 2023/07/03 10:43:28 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

void	initialise(t_parsing *data)
{
	data->paths = NULL;
	data->middle_cmd = NULL;
	data->middle_cmd_path = NULL;
	data->infile = -1;
	data->outfile = -1;
	data->fd[0] = 0;
	data->fd[1] = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_parsing	data;
	t_pid		*pids;
	t_cmd		*cmd;

	data.argc = argc;
	data.argv = argv;
	data.env = env;
	pids = NULL;
	cmd = NULL;
	initialise(&data);
	if (!parsing(argc, argv, env, &data))
		return (error_free(&data, &cmd, &pids), 1);
	if (!create_list_cmd(&cmd, argc, argv))
		return (error_free(&data, &cmd, &pids), 1);
	cmd->in = data.infile;
	if (!loop_process(&data, &pids, &cmd))
		return (1);
	wait_fct(&pids, &data, &cmd);
}
