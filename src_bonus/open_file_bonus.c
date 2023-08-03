/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:26:51 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/08/02 22:22:54 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *file, t_file_type file_type)
{
	int		ret;
	char	*error_message;

	if (file_type == INFILE)
		ret = open(file, O_RDONLY);
	else if (file_type == OUTFILE_TRUNC)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (ret == -1)
	{
		error_message = ft_strjoin("pipex: ", file);
		perror(error_message);
		free(error_message);
		exit(errno);
	}
	return (ret);
}
