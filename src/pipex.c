/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:47:06 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/08/02 21:43:16 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pipedes[2];
	pid_t	pid;

	if (argc != 5)
		invalid_args();
	if (pipe(pipedes) == -1)
	{
		perror(NULL);
		exit(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		exit(errno);
	}
	if (!pid)
		child(argv, pipedes, env);
	waitpid(pid, NULL, WNOHANG);
	parent(argv, pipedes, env);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	if (ft_strchr(cmds[0], '/') == NULL)
		path = get_path(cmds[0], env);
	else
		path = cmds[0];
	if (path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", STD_ERROR);
		ft_putendl_fd(cmds[0], STD_ERROR);
		ft_free_split(cmds);
		exit(COMMAND_NOT_FOUND);
	}
	execve(path, cmds, env);
	free(path);
	ft_free_split(cmds);
	perror(NULL);
	exit(errno);
}

void	child(char **argv, int *pipedes, char **env)
{
	int	fd;

	fd = open_file(argv[1], INFILE);
	dup2(fd, STD_INPUT);
	dup2(pipedes[1], STD_OUTPUT);
	close(pipedes[0]);
	exec(argv[2], env);
}

void	parent(char **argv, int *pipedes, char **env)
{
	int	fd;

	fd = open_file(argv[4], OUTFILE);
	dup2(fd, STD_OUTPUT);
	dup2(pipedes[0], STD_INPUT);
	close(pipedes[1]);
	exec(argv[3], env);
}
