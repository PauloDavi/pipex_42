/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:50:37 by cobli             #+#    #+#             */
/*   Updated: 2023/07/27 06:33:15 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	invalid_args(void)
{
	ft_putendl_fd("Error: Invalid parameters!\n", STD_ERROR);
	ft_putendl_fd("Use: ./pipex <path_infile> <cmd1> <cmdN> <path_outfile>\n",
		STD_ERROR);
	ft_putendl_fd("Please make sure to provide the correct parameters:",
		STD_ERROR);
	ft_putendl_fd("<path_to_infile>: The path to the input file.", STD_ERROR);
	ft_putendl_fd("<cmd[1, 2, ..., N]>: The commands to be executed.",
		STD_ERROR);
	ft_putendl_fd("<path_to_outfile>: The path to the output file.\n",
		STD_ERROR);
	ft_putendl_fd("Example: ./pipex input.txt \"grep hello\" sort output.txt",
		STD_ERROR);
	exit(EXIT_FAILURE);
}

void	invalid_here_doc_args(void)
{
	ft_putendl_fd("Error: Invalid parameters!\n", STD_ERROR);
	ft_putendl_fd("Use: ./pipex here_doc LIMITER <cmd1> <cmdN> <path_outfile>\n",
		STD_ERROR);
	ft_putendl_fd("Please make sure to provide the correct parameters:",
		STD_ERROR);
	ft_putendl_fd("LIMITER: The path to the input file.", STD_ERROR);
	ft_putendl_fd("<cmd[1, 2, ..., N]>: The commands to be executed.",
		STD_ERROR);
	ft_putendl_fd("<path_to_outfile>: The path to the output file.\n",
		STD_ERROR);
	ft_putendl_fd("Ex: ./pipex here_doc LIMITER \"grep hello\" sort output.txt",
		STD_ERROR);
	exit(EXIT_FAILURE);
}
