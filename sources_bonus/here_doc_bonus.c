/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:35:29 by aurore            #+#    #+#             */
/*   Updated: 2023/06/30 11:19:59 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

int	is_here_doc(int argc, char **argv)
{
	if (argc < 6)
		return (0);
	if (ft_strcmp("here_doc", argv[1]) != 0)
		return (0);
	return (1);
}

int	parsing_here_doc(t_parsing *data, char **argv, int argc, char **env)
{
	if (!env)
		return (ft_printf("Error -> No env\n"), 0);
	data->paths = get_paths(env);
	if (!data->paths)
		return (ft_printf("Error -> Paths\n"), 0);
	data->here_doc_file = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0646);
	if (data->here_doc_file == -1)
		return (ft_printf("Error -> Can't create/open file\n"), 0);
	data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0646);
	if (data->outfile == -1)
	{
		close(data->here_doc_file);
		return (ft_printf("Error -> Can't create/open file\n"), 0);
	}
	return (1);
}

int	ft_here_doc(char **argv, int argc, char **env, t_cmd **cmd)
{
	t_parsing	data;
	t_pid		*pids;

	pids = NULL;
	unlink(".here_doc");
	initialise_data(&data, argc, argv, env);
	if (!parsing_here_doc(&data, argv, argc, env))
		return (error_free(&data, cmd), ft_printf("-> Here_doc\n"), 1);
	standart_input(argv, &data);
	close(data.here_doc_file);
	if (!create_list_cmd(cmd, argc, argv, 3))
		return (error_free(&data, cmd), 1);
	data.here_doc_file = open(".here_doc", O_RDONLY);
	if (data.here_doc_file == -1)
		return (error_free(&data, cmd), ft_printf("Error -> Here_doc\n"), 1);
	(*cmd)->in = data.here_doc_file;
	if (!loop_process(&data, &pids, cmd))
		return (free_all(&data, cmd), 1);
	wait_fct(&pids, &data, cmd);
	close(data.here_doc_file);
	unlink(".here_doc");
	return (0);
}

void	standart_input(char **argv, t_parsing *data)
{
	char	*lign;

	lign = "ok";
	while (1)
	{
		ft_putstr_fd("here_doc>", 1);
		lign = get_next_line(0, argv[2]);
		if(!lign)
			break;
		ft_putstr_fd(lign, data->here_doc_file);
		free(lign);
	}
}
