/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:40:09 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/21 11:30:37 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data data, char **argv, char **envp)
{
	int		status;
	// pid_t	parent;
	pid_t	child_1;
	pid_t	child_2;

	pipe(data.end);
	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork: "));
	// if (child_1 == 0)
	ft_child_1(data, argv, envp);
	child_2 = fork();
	if (child_2 < 0)
		return (perror("Fork: "));
	// if (child_2 == 0)
	ft_child_2(data, argv, envp);
	close(data.end[0]);
	close(data.end[1]);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	static t_data	data;

	// DEBUGGING ONLY
	argv[0] = ft_strdup("lldb debug");
	argv[1] = ft_strdup("main.c");
	argv[2] = ft_strdup("cat");
	argv[3] = ft_strdup("wc -l");
	argv[4] = ft_strdup("output.txt");
	argc = 5;
	// DEBUGGING ONLY
	if (argc < 5)
		return (write(1, "To few arguments\n", 18));
	// data = (t_data *)ft_calloc(1, sizeof(data)); //probably not needed!!!!
	ft_init(argv, envp, data);
	if (data.file1 < 0 || data.file2 < 0)
		return (-1);
	pipex(data, argv, envp);
	return (0);
}
