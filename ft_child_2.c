/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:43:56 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/23 16:58:28 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_2(t_data *data, char **argv, char **envp)
/* will read from end[0], will execute cmd2*/
{
	// int		i;
	// char	*cmd_path;
	// char	**cmd;

	// fprintf(stderr, "child_2 entered\n");
	// waitpid(0, NULL, 0);
	data->file_out = open(argv[4], O_RDWR | O_CREAT, 0644, O_TRUNC);
	if (data->file_out == -1)
		return(perror("Open of File 2 failed"));
	// if (access(argv[1], F_OK) == -1)
	// perror("Command 2 not found")
	// 	exit(EXIT_FAILURE);
	close(data->end[1]);
	if (dup2(data->end[0], STDIN_FILENO) < 0)
		return (perror("dup2"));
	close(data->end[0]);
	if (dup2(data->file_out, STDOUT_FILENO) < 0)
		return (perror("dup2"));
	// i = -1;
	// cmd = ft_split(argv[3], ' ');
	// char *buff = NULL;
	// read(data->end[1], buff, 30);
	// fprintf(stderr, "end[0]= %s\n", buff);
	// while (data->mypaths[++i])
	// {
		// data->cmd_path = ft_strjoin(data->mypaths[1], data->cmd2[0]);
		// fprintf(stderr, "%d\n", i);
		// perror("Error11");
		// fprintf(stderr, "cmd_path %s\n", cmd_path);
		execve(data->cmd_path2, data->cmd2, envp);
		// perror("Error22");// <- add perror to debug
		// free(cmd_path);
	// }
	// perror("Command not found");
	// ft_free_array(cmd);
	exit (EXIT_FAILURE);
}
