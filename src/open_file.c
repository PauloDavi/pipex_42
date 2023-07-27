/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:27:01 by cobli             #+#    #+#             */
/*   Updated: 2023/07/27 06:27:03 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY);
	else
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ret == -1)
		exit(EXIT_FAILURE);
	return (ret);
}
