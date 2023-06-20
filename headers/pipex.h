/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:28:34 by aducobu           #+#    #+#             */
/*   Updated: 2023/06/20 13:46:46 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

// get_path.c
char	*ft_trim(char *s);
char	**get_paths(char **env);
void	display_tab(char **tab);
char	*find_path(char **paths, char *cmd);

// frees.c
void	free_path(char **tab);

// get_cmd.c
char	*get_cmd(char *s);
char	*ft_trim2(char *s);

#endif