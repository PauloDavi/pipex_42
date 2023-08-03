/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:27:00 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/08/02 20:46:24 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int	current_cmd;
	int	fd_in;
	int	fd_out;

	if (argc < 5)
		invalid_args();
	if (ft_strncmp(argv[1], HERE_DOC_STR, ft_strlen(HERE_DOC_STR)) == 0)
	{
		if (argc < 6)
			invalid_here_doc_args();
		current_cmd = START_CMD_HERE_DOC;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		current_cmd = START_CMD;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, STD_INPUT);
	}
	while (current_cmd < argc - 2)
		do_pipe(argv[current_cmd++], env);
	dup2(fd_out, STD_OUTPUT);
	exec(argv[current_cmd], env);
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
	ft_putendl_fd(strerror(errno), STD_ERROR);
	exit(errno);
}

void	do_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		pipedes[2];

	if (pipe(pipedes) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (!pid)
	{
		close(pipedes[0]);
		dup2(pipedes[1], STD_OUTPUT);
		exec(cmd, env);
	}
	else
	{
		close(pipedes[1]);
		dup2(pipedes[0], STD_INPUT);
	}
}
