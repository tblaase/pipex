/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:06:14 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 20:30:36 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
/* will append s2 to s1
** will do nothing if s2 is NULL
** this is a modified version, it will ad a '/' between the strings*/
{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (0);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (c == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	c[i++] = '/';
	while (s2[i2] != '\0')
	{
		c[i] = s2[i2];
		i++;
		i2++;
	}
	c[i] = '\0';
	return (c);
}
