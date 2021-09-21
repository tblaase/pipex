/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:55 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 20:47:16 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(char **argv, char **envp, t_data data)
{
	data.file1 = open(argv[1], O_RDONLY);
	data.file2 = open(argv[4], O_RDWR | O_CREAT , 0644, O_TRUNC);
	data.path_from_envp = ft_strdup((envp[25] + 5));
	data.mypaths = ft_split(data.path_from_envp, ':');
	data.cmd1 = ft_strdup(argv[2]);
	data.cmd2 = ft_strdup(argv[3]);
}
