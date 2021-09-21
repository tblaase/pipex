/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:43:56 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 20:38:54 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_2(t_data data, char **argv, char **envp)
/* will read from end[0], will execute cmd2*/
{
	int	status;

	waitpid(-1, &status, 0);
	if (dup2(data.file2, STDOUT_FILENO) < 0)
		return (perror("dup2: "));
	if (dup2(data.end[0], STDIN_FILENO) < 0)
		return (perror("dup2: "));
	close(data.end[1]);
	close(data.file2);
	// execve function for each possible path
	int		i;
	char	*cmd;
	i = -1;
	while (data.mypaths[++i])
	{
		cmd = ft_strjoin(data.mypaths[i], argv[3]); // protect your ft_join
		execve(cmd, &data.cmd2, envp); // if execve succeeds, it exits
		// perror("Error"); <- add perror to debug
		free(cmd); // if execve fails, we free and we try a new path
	}
	exit (EXIT_FAILURE);
}
