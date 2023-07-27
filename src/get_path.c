/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:06:27 by cobli             #+#    #+#             */
/*   Updated: 2023/07/27 06:29:05 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **env);

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	*path_dir;
	char	**path;
	char	**cmds;

	i = -1;
	path_dir = find_path(env);
	if (path_dir == NULL)
		return (cmd);
	path = ft_split(path_dir, ':');
	cmds = ft_split(cmd, ' ');
	while (path[++i])
	{
		path_dir = ft_strjoin(path[i], "/");
		exec = ft_strjoin(path_dir, cmds[0]);
		free(path_dir);
		if (access(exec, F_OK | X_OK) == 0)
			break ;
		free(exec);
		exec = NULL;
	}
	ft_free_split(path);
	ft_free_split(cmds);
	return (exec);
}

static char	*find_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, PATH_STR, 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}
