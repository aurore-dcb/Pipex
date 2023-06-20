#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// get_path.c
char *ft_trim(char *s);
char **get_paths(char **env);
void display_tab(char **tab);
char *find_path(char **paths, char *cmd);

// frees.c
void free_path(char **tab);


#endif