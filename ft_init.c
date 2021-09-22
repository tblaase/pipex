/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:55 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/22 17:40:30 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_get_data(char **argv, char **envp, t_data *data, int i)
/* only exists because of the 25 lines per function limit */
{
	char	*paths;

	paths = ft_strchr(envp[i], '=') + 1;
	data->path_from_envp = ft_strdup(paths);
	data->mypaths = ft_split(data->path_from_envp, ':');
	data->cmd1 = ft_strdup(argv[2]);
	data->cmd2 = ft_strdup(argv[3]);
}

void	ft_init(char **argv, char **envp, t_data *data)
/* will read all the input data and prepare it for further processing */
{
	int		i;

	i = 0;
	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}

	while (envp && envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	ft_get_data(argv, envp, data, i);
	if (!data->path_from_envp || !data->mypaths || !data->cmd1 || !data->cmd2)
		exit(EXIT_FAILURE);
}
