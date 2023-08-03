/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:49:18 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/08/02 22:10:46 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define STD_INPUT 0
# define STD_OUTPUT 1
# define STD_ERROR 2
# define COMMAND_NOT_FOUND 127
# define PATH_STR "PATH="

typedef enum e_file_type
{
	INFILE,
	OUTFILE,
}		t_file_type;

void	exec(char *cmd, char **env);
void	child(char **argv, int *pipedes, char **env);
void	parent(char **argv, int *pipedes, char **env);
void	invalid_args(void);
int		open_file(char *file, t_file_type f);
char	*get_path(char *cmd, char **env);

#endif
