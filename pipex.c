/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:40:09 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/22 19:49:09 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data data, char **argv, char **envp)
{
	int		status;
	pid_t	child_1;
	pid_t	child_2;

	if (pipe(data.end) == -1)
	{
		perror("Pipe failed: ");
		exit(EXIT_FAILURE);
	}
	// write(2, file[0], ft_strlen(file[0]));
	// write(2, "/n", 1);
	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork failed: "));
	if (child_1 == 0)
	{
		ft_child_1(&data, argv, envp);
		close(data.end[1]);
	}
	else
	{
		wait(NULL);
		child_2 = fork();
		if (child_2 < 0)
			return (perror("Fork failed: "));
		if (child_2 == 0)
			ft_child_2(&data, argv, envp);
	}
	if (child_1 != 0 && child_2 != 0)
	{
		waitpid(child_1, &status, 0);//?????
		waitpid(child_2, &status, 0);//?????
		ft_free_struct(&data);
		close(data.end[0]);
	}
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
	// data = (t_data *)ft_calloc(1, sizeof(data)); //nt needed by now
	ft_init(argv, envp, &data);
	if (data.file_in < 0 || data.file_out < 0)
		return (-1);
	pipex(data, argv, envp);
	return (0);
}
