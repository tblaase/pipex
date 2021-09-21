/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:55 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/21 13:41:29 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(char **argv, char **envp, t_data *data)
{
	int		i;
	char	*paths;

	i = 0;
	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	data->file_out = open(argv[4], O_RDWR | O_CREAT, 0644, O_TRUNC);
	if (data->file_out == -1)
	{
		perror(argv[4]); // argc - 1
		close(data->file_in);
		exit(EXIT_FAILURE);
	}
	while (envp && envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	paths = ft_strchr(envp[i], '=') + 1;
	data->path_from_envp = ft_strdup(paths);
	// write(2, paths + 1, ft_strlen(paths + 1));
	// write(2, "\n", 1);
	data->mypaths = ft_split(data->path_from_envp, ':');
	// write(2, data->mypaths[0], ft_strlen(data->mypaths[0]));
	// write(2, "\n", 1);
	// write(2, data->mypaths[1], ft_strlen(data->mypaths[1]));
	// write(2, "\n", 1);
	// write(2, data->mypaths[2], ft_strlen(data->mypaths[2]));
	// write(2, "\n", 1);
	// write(2, data->mypaths[3], ft_strlen(data->mypaths[3]));
	// write(2, "\n", 1);
	// write(2, data->mypaths[4], ft_strlen(data->mypaths[4]));
	// write(2, "\n", 1);
	// write(2, data->mypaths[5], ft_strlen(data->mypaths[5]));
	// write(2, "\n", 1);
	data->cmd1 = ft_strdup(argv[2]);
	data->cmd2 = ft_strdup(argv[3]);
	if (!data->path_from_envp || !data->mypaths || !data->cmd1 || !data->cmd2)
		exit(EXIT_FAILURE);
}
