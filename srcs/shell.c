/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:52 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/24 17:00:59 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			shell(t_list *av_list, t_list **g_env, t_list **l_env)
{
	while (av_list != NULL)
	{
		if (builtin(((t_av *)av_list->content), g_env, l_env) == 0)
			return (0);
//		do_exec(((t_av *)av_list->content), *g_env, *l_env);
		av_list = av_list->next;
	}
	return (0);
}
