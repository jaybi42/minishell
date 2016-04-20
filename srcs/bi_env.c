/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:53:06 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/20 13:30:22 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_env(t_list *env)
{
	ft_putendl("-----START-----");
	while (env != NULL)
	{
		ft_putendl(((t_env *)env->content)->str);
		env = env->next;
	}
	ft_putendl("-----FINISH-----");
}

int			bi_env(t_av *av, t_list **g_env, t_list **l_env)
{
	t_list	*c_env;

	c_env = *g_env;
//	if (av->argc != 0)
//		bi_setenv(av, 1, &c_env, l_env);
//	*av->arg++;
//	if (av->argc > 1)
//		fonction_execve(av);
	while (c_env != NULL)
	{
		ft_putendl(((t_env *)c_env->content)->str);
		c_env = c_env->next;
	}
	return (0);
}
