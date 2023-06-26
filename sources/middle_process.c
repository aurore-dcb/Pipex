/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/26 15:06:34 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../libft/libft.h"

int middle(t_parsing *data, t_pid **pids)
{
	int i;
	
	i = 3;
	while (i < data->argc - 2)
	{
		if (!middle_process(data, pids, i))
		{
			fprintf(stdout, "sortie\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	**get_args2(char *cmd)
{
	char	**args;

	(void)cmd;
	// args = ft_split(cmd, ' ');
	args = NULL;
	if (!args)
		return (NULL);
	return (args);
}

int	middle_process(t_parsing *data, t_pid **pids, int index)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		return (ft_printf("Error pipe\n"), 0);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(data->fd[1], STDOUT_FILENO) == -1 || close(data->fd[0]) == -1
			|| close(data->fd[1]) == -1)
			return (0);
		data->middle_cmd = get_args(data->argv[index]);
		data->middle_cmd_path = find_path(data->paths, data->middle_cmd[0]);
		// data->middle_cmd_path = NULL;
		if (data->middle_cmd_path == NULL)
		{
			return (0);
		}
		execve(data->middle_cmd_path, data->middle_cmd, data->env);
		perror("Error while command execution");
	}
	util(data, pids, pid);
	return (1);
}
