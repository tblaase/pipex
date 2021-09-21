/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:11:28 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/21 17:19:21 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_1(t_data *data, char **file, char **envp)
/* will write to end[1], will execute cmd 1 */
{
	if (dup2(data->file_in, STDIN_FILENO) < 0)
		return (perror("dup2: ")); //not sure if right
	if (dup2(data->end[1], STDOUT_FILENO) < 0)
		return (perror("dup2: "));
	close(data->end[0]);
	// execve function for each possible path
	int		i;
	char	*cmd;
	i = 4;
	while (data->mypaths[++i])
	{
		cmd = ft_strjoin(data->mypaths[i], data->cmd1); // protect your ft_join
		execve(cmd, file, envp); // if execve succeeds, it exits
		perror("Error");// <- add perror to debug
		free(cmd); // if execve fails, we free and we try a new path
	}
	// write(2, "bcdef\n", 6);

	// write(2, "ghijk\n", 6);
	close(data->file_in);
	// write(2, "lmnop\n", 6);
	exit(EXIT_FAILURE);
}
