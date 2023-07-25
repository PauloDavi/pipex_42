#include "pipex.h"

void	invalid_args(void)
{
	ft_putendl_fd("Error: Invalid parameters!\n", STD_ERROR);
	ft_putendl_fd("Usage: ./pipex <path_to_infile> <cmd1> <cmd2> <path_to_outfile>\n", STD_ERROR);
	ft_putendl_fd("Please make sure to provide the correct parameters:", STD_ERROR);
	ft_putendl_fd("<path_to_infile>: The path to the input file.", STD_ERROR);
	ft_putendl_fd("<cmd1>: The first command to be executed.", STD_ERROR);
	ft_putendl_fd("<cmd2>: The second command to be executed.", STD_ERROR);
	ft_putendl_fd("<path_to_outfile>: The path to the output file.\n", STD_ERROR);
	ft_putendl_fd("Example: ./pipex input.txt grep hello sort output.txt", STD_ERROR);
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	else
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		exit(EXIT_FAILURE);
	return (ret);
}

void	free_str_array(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*find_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	*path_dir;
	char	**path;
	char	**cmds;

	i = -1;
	path = ft_split(find_path(env), ':');
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
	free_str_array(path);
	free_str_array(cmds);
	return (exec);
}
