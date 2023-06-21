/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:28:34 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/21 15:43:33 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_parsing
{
	int				argc;
	char			**argv;
	char			**env;
	char			**paths;
	int				fd[2];
	char			**first_cmd;
	char			*first_cmd_path;
	char			**last_cmd;
	char			*last_cmd_path;
	int				infile;
	int				outfile;
}					t_parsing;

typedef struct s_pid
{
	pid_t			pid;
	struct s_pid	*next;
}					t_pid;

// get_path.c
char				*ft_trim(char *s);
char				**get_paths(char **env);
void				display_tab(char **tab);
char				*find_path(char **paths, char *cmd);

// frees.c
void				free_path(char **tab);
void				wait_fct(t_pid **pids);

// get_cmd.c
char				*get_cmd(char *s);
char				*ft_trim2(char *s);
char				**get_args(char *cmd);

// process_child.c
int					first_process(t_parsing *data, t_pid **pids);

// process_parent.c
int					last_process(t_parsing *data, t_pid **pids);

// parsing.c
int					parsing(int argc, char **argv, char **env, t_parsing *data);
t_pid				*ft_lstnew_pipex(pid_t pid);
void				ft_lstadd_back_pipex(t_pid **lst, t_pid *new);

#endif