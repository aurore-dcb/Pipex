/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:13:39 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/28 07:51:34 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../libft/libft.h"

int	middle(t_parsing *data, t_pid **pids)
{
	int	i;

	i = 3;
	while (i < data->argc - 2)
	{
		data->middle_cmd = get_args(data->argv[i]);
		if (data->middle_cmd == NULL)
		{
			ft_printf("Error -> Command\n");
			return (0);
		}
		data->middle_cmd_path = find_path(data->paths, data->middle_cmd[0]);
		if (!data->middle_cmd_path)
			return (0);
		if (!middle_process(data, pids))
			return (0);
		free_tab(data->middle_cmd);
		free(data->middle_cmd_path);
		i++;
	}
	return (1);
}

int	middle_process(t_parsing *data, t_pid **pids)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		return (ft_printf("Error -> Pipe\n"), 0);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(data->fd[1], STDOUT_FILENO) == -1 || close(data->fd[0]) == -1
			|| close(data->fd[1]) == -1)
			return (0);
		execve(data->middle_cmd_path, data->middle_cmd, data->env);
		perror("Error while command execution");
	}
	util(data, pids, pid);
	return (1);
}
