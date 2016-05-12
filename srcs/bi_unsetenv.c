/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 13:29:49 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 12:55:38 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_link(t_list **g_env, t_list *link)
{
	t_list	*prev;

	prev = *g_env;
	if (*g_env == link)
	{
		*g_env = prev->next;
		ft_lstdelone(&prev, free_env);
		return ;
	}
	while (prev->next != link)
		prev = prev->next;
	prev->next = link->next;
	ft_lstdelone(&link, free_env);
}

int			bi_unsetenv(t_av av, t_list **g_env, t_list **l_env)
{
	t_list	*link;

	(void)l_env;
	if (g_env == NULL || *av.arg == NULL)
		return (1);
	link = *g_env;
	while (link != NULL)
	{
		if (ft_strstr(((t_env *)link->content)->str, *av.arg) != NULL)
		{
			unset_link(g_env, link);
			return (0);
		}
		link = link->next;
	}
	return (-1);
}
