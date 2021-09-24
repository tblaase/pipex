/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:31:02 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/24 12:07:08 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_get_path_1(t_data *data)
/* will search for the correct path of command 1
** returns 1 and print error if not found */
{
	int		i;

	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path1 = ft_strjoin(data->mypaths[i++], data->cmd1[0]);
		if (access(data->cmd_path1, F_OK) == 0)
			return (0);
		free(data->cmd_path1);
		data->cmd_path1 = NULL;
	}
	perror("Command 1 not found");
	return (1);
}

static int	ft_get_path_2(t_data *data)
/* will search for the correct path of command 2
** returns 1 and print error if not found */
{
	int		i;

	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path2 = ft_strjoin(data->mypaths[i++], data->cmd2[0]);
		if (access(data->cmd_path2, F_OK) == 0)
			return (0);
		free(data->cmd_path2);
		data->cmd_path2 = NULL;
	}
	perror("Command 2 not found");
	return (1);
}

int	ft_get_paths(t_data *data)
/* will find the correct path of the function, returns 1 if not found*/
{
	int	a;
	int	b;

	a = ft_get_path_1(data);
	b = ft_get_path_2(data);
	if (a == 1 || b == 1)
	{
		ft_free_struct(data);
		return (1);
	}
	return (0);
}
