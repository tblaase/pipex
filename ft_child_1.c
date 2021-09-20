/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:11:28 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 15:09:54 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_1(t_data data)
/* will write to end[1], will execute cmd 1 */
{
	if (dup2(data.file1, STDIN_FILENO) < 0)
		return (perror("dup2: ")); //not sure if right
	if (dup2(data.end[1], STDOUT_FILENO) < 0)
		return (perror("dup2: "));
	close(data.end[0]);
	close(data.file1);
	// execve function for each possible path
	exit(EXIT_FAILURE);
}
