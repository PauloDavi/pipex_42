/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:01:13 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/08/02 22:11:13 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	here_doc_put_in(char **argv, int *pipedes);

void	here_doc(char **argv)
{
	int		pipedes[2];
	pid_t	pid;

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
		here_doc_put_in(argv, pipedes);
	else
	{
		close(pipedes[1]);
		dup2(pipedes[0], STD_INPUT);
		wait(NULL);
	}
}

static void	here_doc_put_in(char **argv, int *pipedes)
{
	char	*line;
	char	*limiter;
	size_t	limiter_len;

	limiter = argv[2];
	limiter_len = ft_strlen(argv[2]);
	close(pipedes[0]);
	while (1)
	{
		line = get_next_line(STD_INPUT);
		if (ft_strncmp(line, limiter, limiter_len) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, pipedes[1]);
		free(line);
	}
}
