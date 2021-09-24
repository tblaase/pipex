/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:55:10 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/24 12:29:20 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_c(const char *s, char c, int i)
/* finds the next occurance of char c */
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static unsigned int	ft_count_words(const char *s, char c)
/* count the number of "words" within the given string */
{
	int	str_nbr;
	int	i;

	if (!s)
		return (0);
	str_nbr = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			str_nbr++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		str_nbr++;
	return (str_nbr);
}

static void	ft_write_words(const char *s, char c, char **mainstr,
	unsigned int b)
/* will write the single "words" into the char **mainstr */
{
	unsigned int	a;
	unsigned int	i;
	size_t			z;

	i = 0;
	a = 0;
	z = 0;
	while (a < b)
	{
		i = z + i;
		while (s[i] && s[i] == c)
			i++;
		z = ft_find_c(s, c, i) - i;
		mainstr[a] = (char *)ft_substr(s, i, z);
		a++;
	}
	mainstr[a] = NULL;
}

char	**ft_split(const char *s, char c)
/* will split into single strings after every delimiter c */
{
	char			**mainstr;
	unsigned int	b;

	if (!s)
		return (NULL);
	b = ft_count_words(s, c);
	mainstr = (char **)malloc(b * sizeof(char *) + 1 * sizeof(char *));
	if (!mainstr)
		return (NULL);
	ft_write_words(s, c, mainstr, b);
	return (mainstr);
}
