/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/15 21:47:12 by jguthert         ###   ########.fr       */
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
	char		*cmd;
	char		*value;
}				t_env;

typedef struct	s_av
{
	char		**av_l;
	int			cmd;
}				t_av;


/*
**Name: Env
**File: get_env.c
**Desc: Generate env or get it
*/

int				get_env(t_list **e);

#endif
