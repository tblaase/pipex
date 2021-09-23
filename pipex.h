/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:34:57 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/23 16:56:21 by tblaase          ###   ########.fr       */
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
	int		file_in;
	int		file_out;
	char	**mypaths;
	char	*cmd_path1;
	char	*cmd_path2;
	char	**cmd1;
	char	**cmd2;
}				t_data;

/* **********  ********** */
/* ********** FUNCTIONS ********** */
void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_init(char **argv, char **envp, t_data *data);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_child_1(t_data *data, char **file, char **envp);
void	ft_child_2(t_data *data, char **file, char **envp);
void	ft_free_struct(t_data *data);
int		ft_get_paths(t_data *data);

#endif
