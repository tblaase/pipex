/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:55 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/23 16:46:40 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init(char **argv, char **envp, t_data *data)
/* will read all the input data and prepare it for further processing */
{
	int		i;
	char	*paths;

	i = 0;
	while (envp && envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	paths = ft_strchr(envp[i], '=') + 1;
	data->mypaths = ft_split(paths, ':');
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd1 || !data->cmd2 || !data->mypaths)
		exit(EXIT_FAILURE);
	return (0);
}
