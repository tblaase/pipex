/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:35:24 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 14:35:34 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = (char *)malloc(nelem * elsize);
	if (ptr == NULL)
		return (0);
	while (i < nelem * elsize)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
