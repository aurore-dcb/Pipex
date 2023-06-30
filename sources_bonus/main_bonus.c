/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:13:20 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/30 14:15:46 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

void	initialise_data(t_parsing *data, int argc, char **argv, char **env)
{
	data->argc = argc;
	data->argv = argv;
	data->env = env;
	data->paths = NULL;
	data->infile = -1;
	data->outfile = -1;
	data->here_doc_file = -1;
	data->middle_cmd = NULL;
	data->middle_cmd_path = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_parsing	data;
	t_pid		*pids;
	t_cmd		*cmd;

	pids = NULL;
	cmd = NULL;
	if (is_here_doc(argc, argv))
		return (ft_here_doc(argv, argc, env, &cmd));
	else
	{
		initialise_data(&data, argc, argv, env);
		if (!parsing(argc, argv, env, &data))
			return (error_free(&data, &cmd, &pids), 1);
		if (!create_list_cmd(&cmd, argc, argv, 2))
			return (error_free(&data, &cmd, &pids), 1);
		cmd->in = data.infile;
		if (!loop_process(&data, &pids, &cmd))
			return (1);
		wait_fct(&pids, &data, &cmd);
	}
}
