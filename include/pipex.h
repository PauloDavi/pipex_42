#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
#include <string.h>
# include <errno.h>

#define STD_INPUT 0
#define STD_OUTPUT 1
#define STD_ERROR 2
#define COMAND_NOT_FOUND 127

void	exec(char *cmd, char **env);
void	child(char **argv, int *pipedes, char **env);
void	parent(char **argv, int *pipedes, char **env);
void	invalid_args(void);
int	open_file(char *file, int in_or_out);
void	free_str_array(char **tab);
char	*find_path(char **env);
char	*get_path(char *cmd, char **env);

#endif
