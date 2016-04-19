/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/19 19:20:35 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** TODO: Suppr stdio
*/

# include <stdio.h> //

# include "libft.h"

typedef struct	s_env
{
	char		*name;
	char		*value;
	char		*str;
}				t_env;

typedef struct	s_error
{
	bool		cmd;
	char		*str;
	bool		arg;
}				t_error;

typedef int		(*t_bi_fptr)(char **, int, t_list **, t_list **);

typedef struct	s_builtin
{
	char		*key;
	t_bi_fptr	value;
}				t_builtin;

typedef struct	s_av
{
	char		*cmd;
	char		**arg;
	int			argc;
}				t_av;

/*
**Name: Parsing
**File: read.c get_env.c
**Desc: Parse read and env
*/

int				read_i(t_list **av);
int				get_env(t_list **g_env, t_list **l_env);

/*
**Name: Shell
**File: shell.c
**Desc: Do shell functions
*/

int				shell(t_list *av, t_list **g_env, t_list **l_env);

/*
**Name: builtin
**File: builtin.c bi_cd.c bi_env.c bi_exit.c
**Desc: Do the builtin if it exist
*/

int				builtin(t_av *av, t_list **g_env, t_list **l_env);
int				bi_cd(char **av, int argc, t_list **g_env, t_list **l_env);
int				bi_env(char **av, int argc, t_list **g_env, t_list **l_env);
int				bi_unsetenv(char **av, int argc, t_list **g_env, t_list **l_env);
int				bi_setenv(char **av, int argc, t_list **g_env, t_list **l_env);
int				bi_exit(char **av, int argc, t_list **g_env, t_list **l_env);

/*
**Name: Free list
**File: free_list.c
**Desc: free list functions to work with ft_lstdel() && ft_lstdelone()
*/

void			free_av(void *content, size_t size);
void			free_env(void *content, size_t size);

/*
**Name: Print error
**File: print_error.c
**Desc: print error from builtins
*/

void			print_error(t_av *av, int error);

#endif
