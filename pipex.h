/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:34:57 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/20 15:14:46 by tblaase          ###   ########.fr       */
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
// # define STDIN_FILENO 0
// # define STDOUT_FILENO 1

/* ********** STRUCT TO HAND VARIABLES BETWEEN FUNCTIONS ********** */
typedef struct s_data
{
	int		end[2];
	char	*path_from_envp;
	char	**mypaths;
	char	**mycmdargs;
	char	*cmd1;
	char	*cmd2;
	char	**mypaths;
	char	**mycmdargs;
	int		*file1;
	int		*file2;
}				t_data;

/* **********  ********** */
/* ********** FUNCTIONS ********** */
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_init(int argc, char **argv, char **envp, t_data data);
#endif
