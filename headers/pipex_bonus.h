/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:43:22 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/29 13:06:20 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int				infile;
	int				outfile;
	int				here_doc_file;
	char			**middle_cmd;
	char			*middle_cmd_path;
}					t_parsing;

typedef struct s_cmd
{
	int				in;
	char			*arg;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_pid
{
	pid_t			pid;
	struct s_pid	*next;
}					t_pid;

void				initialise_data(t_parsing *data);

// get_path_bonus.c
char				*ft_trim(char *s);
char				**get_paths(char **env);
char				*find_path(char **paths, char *cmd);

// frees_bonus.c
void				error_free(t_parsing *data, t_cmd **cmd);
void				free_tab(char **tab);
void				wait_fct(t_pid **pids, t_parsing *data, t_cmd **cdm);
void				free_all(t_parsing *data, t_cmd **cmd);
void				ft_lstclear_cmd(t_cmd **lst);

// get_cmd_bonus.c
char				*get_cmd(char *s);
char				**get_args(char *cmd);

// parsing_bonus.c
int					parsing(int argc, char **argv, char **env, t_parsing *data);
t_pid				*ft_lstnew_pipex(pid_t pid);
void				ft_lstadd_back_pipex(t_pid **lst, t_pid *new);

// lst_cmd_bonus.c
t_cmd				*ft_lstnew_cmd(char *arg);
int					ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
int	create_list_cmd(t_cmd **cmd, int argc, char **argv, int i);

// process_bonus.c
int					loop_process(t_parsing *data, t_pid **pids, t_cmd **cmd);
int					ft_process(t_parsing *data, t_pid **pids, t_cmd *cmd);
int					ft_child(t_cmd *cmd, t_parsing *data);

// here_doc_bonus.c
int					is_here_doc(int argc, char **argv);
int					parsing_here_doc(t_parsing *data, char **argv, int argc, char **env);
int					ft_here_doc(char **argv, int argc, char **env, t_cmd **cmd);
void				standart_input(char **argv, t_parsing *data);

#endif