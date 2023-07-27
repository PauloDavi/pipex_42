/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:26:30 by cobli             #+#    #+#             */
/*   Updated: 2023/07/27 06:28:52 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# define START_CMD 2
# define START_CMD_HERE_DOC 3
# define HERE_DOC_STR "here_doc"
# define STD_INPUT 0
# define STD_OUTPUT 1
# define STD_ERROR 2
# define COMMAND_NOT_FOUND 127
# define PATH_STR "PATH="

void	invalid_args(void);
void	invalid_here_doc_args(void);
void	here_doc(char **argv);
void	exec(char *cmd, char **env);
void	do_pipe(char *cmd, char **env);
int		open_file(char *file, int in_or_out);
char	*get_path(char *cmd, char **env);

#endif
