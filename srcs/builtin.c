/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:03:36 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/18 12:49:08 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin const  g_builtin_list[5] = {
    {"cd", bi_cd},
    {"setenv", bi_setenv},
    {"unsetenv", bi_unsetenv},
    {"env", bi_setenv},
    {"exit", bi_exit},
};

int			builtin(t_av *av, t_list **g_env, t_list **l_env)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(g_builtin_list[i].key, av->cmd) == 0)
		{
			g_builtin_list[i].value(av, g_env, l_env);
			return (1);
		}
		i++;
	}
	return (0);
}
