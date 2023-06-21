/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:42:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 15:44:12 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **env)
{
	t_parsing data;
	t_pid *pids;

	parsing(argc, argv, env, &data);
	data.argc = argc;
	data.argv = argv;
	data.env = env;
	if (pipe(data.fd) == -1)
	{
		ft_printf("Error\n");
		return (1);
		//fct free all
	}
	first_process(&data, &pids);
	last_process(&data, &pids);
	wait_fct(&pids);
}
