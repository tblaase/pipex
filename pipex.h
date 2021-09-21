/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:34:57 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/21 17:19:31 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

/* ********** STRUCT TO HAND VARIABLES BETWEEN FUNCTIONS ********** */
typedef struct s_data
{
	int		end[2];
	char	*path_from_envp;
	char	**mypaths;
	// char	**mycmdargs;
	char	*cmd1;
	char	*cmd2;
	int		file_in;
	int		file_out;
}				t_data;

/* **********  ********** */
/* ********** FUNCTIONS ********** */
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_init(char **argv, char **envp, t_data *data);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_child_1(t_data *data, char **file, char **envp);
void	ft_child_2(t_data *data, char **file, char **envp);

#endif
