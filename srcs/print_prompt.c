/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:39:33 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/21 14:02:05 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		local_prompt(t_list *l_env)
{
	while (l_env != NULL)
	{
		if (ft_strcmp(((t_env *)l_env->content)->name, "USER") == 0)
		{
			ft_putstr("\033[1;33");
			ft_putstr(((t_env *)l_env->content)->value);
			return (0);
		}
		l_env = l_env->next;
	}
	return (1);
}

static	int		global_prompt(t_list *g_env)
{
	while (g_env != NULL)
	{
		if (ft_strcmp(((t_env *)g_env->content)->name, "HOST") == 0)
		{
			ft_putstr(((t_env *)g_env->content)->value);
			return (0);
		}
		g_env = g_env->next;
	}
	return (1);
}

void			print_prompt(int rand, t_list *g_env, t_list *l_env)
{
	int const	color[14] = {30, 31, 32, 33, 34, 35, 36, 37,
						   40, 41, 42, 43, 44, 45, 46, 47};
	int const	style[4] = {0, 1, 4, 7};
	char const	cavas = {"\033[1;33m"};
	char		*str;

	str = ft_strnew(8);
	while (*str !=)
	{
		ft_itoa(style[rand % 4]);
		ft_itoa(color[rand % 14]);
	}
	ftv_pushback(&acc, );
	ftv_pushback(&acc, );
	ft_putstr(acc->data);
	ft_
	if (global_prompt(g_env) == 0)
		;
	else if (local_prompt(l_env) == 0)
		;
	ft_putstr("$>");
	ft_putstr("\033[0m");
}
