/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:34:57 by tblaase           #+#    #+#             */
/*   Updated: 2021/09/27 19:54:53 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

/* ********** STRUCT TO HAND VARIABLES BETWEEN FUNCTIONS ********** */
typedef struct s_data
{
	int		flag1;
	int		flag2;
	int		end[2];
	int		file_in;
	int		file_out;
	char	**mypaths;
	char	*cmd_path1;
	char	*cmd_path2;
	char	**cmd1;
	char	**cmd2;
}				t_data;

/* ********** FUNCTIONS ********** */
void	ft_init(char **argv, char **envp, t_data *data);
void	ft_child_1(t_data *data, char **file, char **envp);
void	ft_child_2(t_data *data, char **file, char **envp);
void	ft_free_struct(t_data *data);
void	ft_get_paths(t_data *data);

#endif
