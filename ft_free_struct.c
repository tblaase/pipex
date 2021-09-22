/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:05:13 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/22 12:14:03 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_struct(t_data *data)
/* will free all allocated data of the data struct */
{
	free(data->path_from_envp);
	ft_free_array(data->mypaths);
	free(data->cmd1);
	free(data->cmd2);
}
