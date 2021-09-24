/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:05:13 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/24 10:31:39 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_struct(t_data *data)
/* will free all allocated data of the data struct */
{
	ft_free_array(data->mypaths);
	ft_free_array(data->cmd1);
	ft_free_array(data->cmd2);
	free(data->cmd_path1);
	data->cmd_path1 = NULL;
	free(data->cmd_path2);
	data->cmd_path2 = NULL;
}
