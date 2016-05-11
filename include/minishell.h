/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/11 14:31:29 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** TODO: Suppr stdio
*/

# include <stdio.h> //

# include "libft.h"

# define INIT_ALL(CMD,AV1,AV2) (char *[]){CMD, AV1, AV2, NULL}
# define INIT_ARG(AV1,AV2) (char *[]){AV1, AV2, NULL}
# define INIT_AV(A,B,C,D) ((t_av){A, INIT_ARG(B, C), D, INIT_ALL(A, B, C)})

typedef void	(*sig_t) (int);

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

typedef struct	s_av
{
	char		*cmd;
	char		**arg;
	int			argc;
	char		**all;
}				t_av;

typedef int		(*t_bi_fptr)();

typedef struct	s_builtin
{
	char		*key;
	t_bi_fptr	value;
}				t_builtin;

/*
**Name: Parsing
**File: read.c get_env.c
**Desc: Parse read and env
*/

int				read_init(t_list **av_list);
int				init_env(t_list **g_env, t_list **l_env);

/*
**Name: Shell
**File: shell.c print_prompt.c do_exec.c
**Desc: Do shell functions
*/

int				shell(t_list *av_list, t_list **g_env, t_list **l_env);
int				do_exec(t_av av, t_list *g_env, t_list *l_env);
void			print_prompt(int rand, t_list *g_env, t_list *l_env);
void			catch_sig(void);

/*
**Name: builtin
**File: builtin.c bi_*.c
**Desc: Do the builtin if it exist
*/

int				builtin(t_av av, t_list **g_env, t_list **l_env);
int				bi_cd(t_av av, t_list **g_env, t_list **l_env);
int				bi_env(t_av av, t_list **g_env, t_list **l_env);
int				bi_unsetenv(t_av av, t_list **g_env, t_list **l_env);
int				bi_setenv(t_av av, t_list **g_env, t_list **l_env);
int				bi_exit(t_av av, t_list **g_env, t_list **l_env);
int				bi_getenv(t_av av, t_list **g_env, t_list **l_env);

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

int				print_error(t_av av, int error);

#endif
