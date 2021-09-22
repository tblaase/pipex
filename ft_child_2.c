/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:43:56 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/22 20:13:19 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_2(t_data *data, char **argv, char **envp)
/* will read from end[0], will execute cmd2*/
{
	// int	status;
	// waitpid(-1, &status, 0);
	// dup2(STDIN_FILENO, data->file_in);
	// dup2(STDOUT_FILENO, data->end[1]);
	// perror("Error");
	// close(data->end[1]);
	data->file_out = open(argv[4], O_RDWR | O_CREAT, 0644, O_TRUNC);
	fprintf(stderr, "file_out fd: %d\n", data->file_out);
	if (data->file_out == -1)
	{
		perror(argv[4]);
		close(data->file_in);
		exit(EXIT_FAILURE);
	}
	// fprintf(stderr, "ENDS: %d, %d\n", data->end[0], data->end[1]);
	// fprintf(stderr,"HEREbefore %d, %d\n", data->file_in, data->file_out);
	if (dup2(data->end[0], STDIN_FILENO) < 0)
		return (perror("dup2: "));
	if (dup2(data->file_out, STDOUT_FILENO) < 0)
		return (perror("dup2: "));
	// fprintf(stderr,"HEREafter %d, %d\n", data->file_in, data->file_out);
	// fprintf(stdout, "Hello looser\n");
	// write(1, "HELLOOOO", 8);
	// close(data->file_out);
	// exit(EXIT_SUCCESS);
	// execve function for each possible path
	// ENDLESS LOOP SOMEWHERE HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int		i;
	char	*cmd_path;
	char	**cmd;

	i = -1;
	cmd = ft_split(argv[3], ' ');
	while (data->mypaths[++i])
	{
		// fprintf(stderr, "%s, %s, %s\n", data->mypaths[i], cmd[0], cmd[1]);
		cmd_path = ft_strjoin(data->mypaths[i], cmd[0]); // protect your ft_join
		fprintf(stderr, "tested: %s\n", cmd_path);
		fprintf(stderr, "command: %s\n", cmd[0]);
		execve(cmd_path, cmd, envp); // if execve succeeds, it exits
		perror("Error");// <- add perror to debug
		free(cmd_path); // if execve fails, we free and we try a new path
	}
	close(data->file_out);
	ft_free_array(cmd);
	exit (EXIT_FAILURE);
}
