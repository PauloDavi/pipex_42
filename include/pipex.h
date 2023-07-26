/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:49:18 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/25 21:49:29 by pdavi-al         ###   ########.fr       */
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

void	exec(char *cmd, char **env);
void	child(char **argv, int *pipedes, char **env);
void	parent(char **argv, int *pipedes, char **env);
void	invalid_args(void);
int		open_file(char *file, int in_or_out);
void	free_str_array(char **tab);
char	*find_path(char **env);
char	*get_path(char *cmd, char **env);

#endif
