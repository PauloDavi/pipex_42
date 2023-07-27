/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 06:26:09 by cobli             #+#    #+#             */
/*   Updated: 2023/07/27 06:33:49 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	invalid_args(void)
{
	ft_putendl_fd("Error: Invalid parameters!\n", STD_ERROR);
	ft_putendl_fd("Use: ./pipex <path_infile> <cmd1> <cmd2> <path_outfile>\n",
		STD_ERROR);
	ft_putendl_fd("Please make sure to provide the correct parameters:",
		STD_ERROR);
	ft_putendl_fd("<path_to_infile>: The path to the input file.", STD_ERROR);
	ft_putendl_fd("<cmd1>: The first command to be executed.", STD_ERROR);
	ft_putendl_fd("<cmd2>: The second command to be executed.", STD_ERROR);
	ft_putendl_fd("<path_to_outfile>: The path to the output file.\n",
		STD_ERROR);
	ft_putendl_fd("Ex: ./pipex input.txt \"grep hello\" sort output.txt",
		STD_ERROR);
	exit(EXIT_FAILURE);
}
