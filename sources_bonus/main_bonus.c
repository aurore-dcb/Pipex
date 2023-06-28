/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:13:20 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/28 10:41:45 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
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
	t_cmd		*cmd;

	data.argc = argc;
	data.argv = argv;
	data.env = env;
	cmd = NULL;
	initialise(&data);
	if (!parsing(argc, argv, env, &data))
		return (error_free(&data, &cmd), 1);
	if (!create_list_cmd(&cmd, argc, argv))
		return (ft_printf("Error -> list commande\n"), error_free(&data, &cmd), 1);
	cmd->in = data.infile;
	pids = NULL;
	if (!loop_process(&data, &pids, &cmd))
	{
		free_all(&data, &cmd);
		return (1);
	}
	// if (!first_process(&data, &pids) || !middle(&data, &pids)
	// 	|| !last_process(&data, &pids))
	// {
	// 	free_all(&data, &cmd);
	// 	return (1);
	// }
	wait_fct(&pids, &data, &cmd);
}
