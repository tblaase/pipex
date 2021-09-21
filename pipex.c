/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:40:09 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/21 17:23:57 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data data, char **argv, char **envp)
{
	int		status;
	pid_t	child_1;
	pid_t	child_2;
	char	**file;

	pipe(data.end);
	// pipe protection needed
	file = ft_split(argv[1], ' ');
	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork: "));
	if (child_1 == 0)
	{
		ft_child_1(&data, file, envp);
		close(data.end[1]);
	}
	else
	{
		wait(NULL);
		ft_free_array(file);
		file = ft_split(argv[1], ' ');
		child_2 = fork();
		if (child_2 < 0)
			return (perror("Fork: "));
		if (child_2 == 0)
			ft_child_2(&data, argv, envp);
	}

	if (child_1 != 0 && child_2 != 0)
	{
		waitpid(child_1, &status, 0);//?????
		waitpid(child_2, &status, 0);//?????
		ft_free_array(file);
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
	// argv[3] = ft_strdup("wc");
	// argv[4] = ft_strdup("output.txt");
	// argc = 5;
	// LLDB DEBUGGING ONLY
	if (argc < 5)
		return (write(1, "To few arguments\n", 18));
	// data = (t_data *)ft_calloc(1, sizeof(data)); //nt needed by now
	ft_init(argv, envp, &data);
	if (data.file_in < 0 || data.file_out < 0)
		return (-1);
	pipex(data, argv, envp);
	return (0);
}
