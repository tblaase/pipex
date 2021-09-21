/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:17:15 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 18:37:36 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
/* will return the length of a string
** will return 0 if the string is empty */
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
