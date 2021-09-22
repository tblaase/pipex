/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:11:28 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/22 18:19:49 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_1(t_data *data, char **argv, char **envp)
/* will write to end[1], will execute cmd 1 */
{
	if (dup2(data->file_in, STDIN_FILENO) < 0)
		return (perror("dup2 failed: ")); //not sure if right
	if (dup2(data->end[1], STDOUT_FILENO) < 0)
		return (perror("dup2 failed: "));
	close(data->end[0]);
	// execve function for each possible path
	int		i;
	int		out;
	char	*cmd_path;
	char	**cmd;

	i = -1;
	cmd = ft_split(argv[2], ' ');
	// write(2, "HERE\n", 5);
	// write(2, data->mypaths[3], ft_strlen(data->mypaths[3]));
	// write(2, "\n", 1);
	while (data->mypaths[++i])
	{
		out = 0;
		cmd_path = ft_strjoin(data->mypaths[i], data->cmd1);
		// write(2, "\nsearched: ", 10);
		// write(2, cmd_path, ft_strlen(cmd_path));
		// write(2, "\n", 1);
		out = execve(cmd_path, cmd, envp); // if execve succeeds, it exits
		// perror("Error");// <- add perror to debug
		free(cmd_path);
		cmd_path = NULL;
		// if (out == 0)
		// {
		// 	write(2, "SUCCESS!", 8);
		// 	perror("Success!");
		// 	close(data->file_in);
		// 	ft_free_array(cmd);
		// 	exit(EXIT_SUCCESS);
		// }
	}
	free(cmd_path);
	close(data->file_in);
	ft_free_array(cmd);
	exit(EXIT_FAILURE);
}
