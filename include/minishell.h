/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/16 19:55:10 by jguthert         ###   ########.fr       */
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

typedef int		(*t_bi_fptr)();

typedef struct	s_builtin
{
	char		*key;
	t_bi_fptr	value;
}				t_builtin;

typedef struct	s_av
{
	char		*av;
	char		*cmd;
}				t_av;

/*
**Name: Env
**File: get_env.c
**Desc: Generate env or get it
*/

int				get_env(t_list **g_env, t_list **l_env);

/*
**Name: Parse incoming
**File: read.c
**Desc: Parse incoming
*/

int				read_i(t_list **av);

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

int				builtin(t_av *av);
void			bi_cd(char *value);
void			bi_env(char *value);
void			bi_unsetenv(char *value);
void			bi_setenv(char *value);
void			bi_exit(char *value);

/*
**Name: Free list
**File: free_list.c
**Desc: free list functions to work with ft_lstdel()
*/

void			free_av(void *content, size_t size);

#endif
