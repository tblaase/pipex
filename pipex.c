/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:40:09 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/27 21:27:09 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipex(t_data *data, char **argv, char **envp)
/* this is the parent process, it will fork the two child processes
** and wait for them */
{
	pid_t	child_1;
	pid_t	child_2;

	child_1 = fork();
	if (child_1 < 0)
		perror("Fork failed");
	if (child_1 == 0)
		ft_child_1(data, argv, envp);
	child_2 = fork();
	if (child_2 < 0)
		perror("Fork failed");
	if (child_2 == 0)
		ft_child_2(data, argv, envp);
	waitpid(-1, NULL, 0);
	ft_free_struct(data);
}

int	main(int argc, char **argv, char **envp)
/* will check for input errors and pipe errors */
{
	static t_data	data;

	if (argc != 5)
	{
		perror("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\nError");
		return (1);
	}
	if (pipe(data.end) == -1)
	{
		perror("Pipe failed");
		return (1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		perror("File 1 not found");
		data.flag1 = 1;
	}
	ft_init(argv, envp, &data);
	ft_get_paths(&data);
	ft_pipex(&data, argv, envp);
	return (0);
}
