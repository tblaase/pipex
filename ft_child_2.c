/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:43:56 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/24 11:56:18 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_2(t_data *data, char **argv, char **envp)
/* will read from end[0], will execute cmd2*/
{
	data->file_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->file_out == -1)
		return (perror("Open of File 2 failed"));
	close(data->end[1]);
	if (dup2(data->end[0], STDIN_FILENO) < 0)
		return (perror("dup2"));
	close(data->end[0]);
	if (dup2(data->file_out, STDOUT_FILENO) < 0)
		return (perror("dup2"));
	execve(data->cmd_path2, data->cmd2, envp);
	exit(EXIT_FAILURE);
}
