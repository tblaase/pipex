/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:11:28 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/27 20:31:55 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_1(t_data *data, char **argv, char **envp)
/* will write to end[1], will execute cmd 1 */
{
	close(data->end[0]);
	if (dup2(data->end[1], STDOUT_FILENO) < 0)
		return (perror("dup2 failed"));
	close(data->end[1]);
	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in == -1)
		return (perror("Open of File 1 failed"));
	if (dup2(data->file_in, STDIN_FILENO) < 0)
		return (perror("dup2 failed"));
	if (!data->flag1)
		execve(data->cmd_path1, data->cmd1, envp);
	exit(EXIT_FAILURE);
}
