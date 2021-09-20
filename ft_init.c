/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:55 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 15:14:32 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(int argc, char **argv, char **envp, t_data data)
{
	data.file1 = open(argv[1], O_RDONLY);
	data.file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	data.path_from_envp = ft_substr(envp, "PATH");
	data.mypaths = ft_split(data.path_from_envp, ":");
	if (argc - 1 == 4)
	{
		data.cmd1 = open(argv[2], O_RDONLY);
		data.cmd2 = open(argv[3], O_RDONLY);
	}
	else
		data.mycmdargs = ft_split(argv[2], " ");
}
