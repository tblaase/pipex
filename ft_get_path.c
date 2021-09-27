/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:31:02 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/27 21:43:23 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_get_path_1(t_data *data)
/* will search for the correct path of command 1, print error if not found */
{
	int		i;
	char	*temp;

	if (access(data->cmd1[0], F_OK) == 0)
	{
		data->cmd_path1 = ft_strdup(data->cmd1[0]);
		temp = ft_strrchr(data->cmd1[0], '/') + 1;
		free(data->cmd1[0]);
		data->cmd1[0] = ft_strdup(temp);
		return ;
	}
	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path1 = ft_strjoin(data->mypaths[i++], data->cmd1[0], '/');
		if (access(data->cmd_path1, F_OK) == 0)
			return ;
		free(data->cmd_path1);
		data->cmd_path1 = NULL;
	}
	perror("Command 1 not found");
	data->flag1 = 1;
}

static void	ft_get_path_2(t_data *data)
/* will search for the correct path of command 2, print error if not found */
{
	int		i;
	char	*temp;

	if (access(data->cmd2[0], F_OK) == 0)
	{
		data->cmd_path2 = ft_strdup(data->cmd2[0]);
		temp = ft_strrchr(data->cmd2[0], '/') + 1;
		free(data->cmd2[0]);
		data->cmd2[0] = ft_strdup(temp);
		fprintf(stderr, "HELLO\n");
		return ;
	}
	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path2 = ft_strjoin(data->mypaths[i++], data->cmd2[0], '/');
		if (access(data->cmd_path2, F_OK) == 0)
			return ;
		free(data->cmd_path2);
		data->cmd_path2 = NULL;
	}
	perror("Command 2 not found");
	data->flag2 = 1;
}

void	ft_get_paths(t_data *data)
/* will find the correct path of the function
** print error if not found */
{
	ft_get_path_1(data);
	ft_get_path_2(data);
}
