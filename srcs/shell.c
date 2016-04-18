/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:52 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/18 12:29:35 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			shell(t_list *av, t_list **g_env, t_list **l_env)
{
	while (av != NULL)
	{
		if (builtin(((t_av *)av->content), g_env, l_env) == 0)
			ft_putstr("No builtin\n");
		av = av->next;
	}
	return (0);
}
