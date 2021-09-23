/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:11:28 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/23 16:21:17 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_1(t_data *data, char **argv, char **envp)
/* will write to end[1], will execute cmd 1 */
{
	int		fd;

	// fprintf(stderr, "child_1 entered\n");
	close(data->end[0]);
	if (dup2(data->end[1], STDOUT_FILENO) < 0)
		return (perror("dup2 failed"));
	close (data->end[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Open of File 1 failed"));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (perror("dup2 failed"));
	// i = -1;
	// cmd = ft_split(argv[2], ' ');
	// while (data->mypaths[++i])
	// {
		// cmd_path = ft_strjoin(data->mypaths[1], data->cmd1[0]);
		// perror("Error1");// <- add perror to debug
		execve(data->cmd_path1, data->cmd1, envp);
		// perror("Error2");// <- add perror to debug
		// free(cmd_path);
		// cmd_path = NULL;
	// }
	// ft_free_array(cmd);
	exit(EXIT_FAILURE);
}
