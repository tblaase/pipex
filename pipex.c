/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:40:09 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/23 18:10:54 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipex(t_data *data, char **argv, char **envp)
{
	pid_t	child_1;
	pid_t	child_2;

	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork failed"));
	if (child_1 == 0)
		ft_child_1(data, argv, envp);
	wait(NULL);
	child_2 = fork();
	if (child_2 < 0)
		return (perror("Fork failed"));
	if (child_2 == 0)
		ft_child_2(data, argv, envp);
	// wait(NULL);
	// waitpid(child_2, NULL, 0);
	ft_free_struct(data);
}

int	main(int argc, char **argv, char **envp)
{
	static t_data	data;

	// LLDB DEBUGGING ONLY
	// argv[0] = ft_strdup("lldb debug");
	// argv[1] = ft_strdup("main");
	// argv[2] = ft_strdup("less");
	// argv[3] = ft_strdup("wc -l");
	// argv[4] = ft_strdup("output.txt");
	// argc = 5;
	// LLDB DEBUGGING ONLY
	if (argc < 5)
	{
		perror("Usage: './pipex file1 cmd1 cmd2 file2' \nError");
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
		return (1);
	}
	// data = (t_data *)ft_calloc(1, sizeof(data)); //not needed by now
	ft_init(argv, envp, &data);
	if (ft_get_paths(&data) == 1)
		return (1);
	ft_pipex(&data, argv, envp);
	return (0);
}
