/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:39:33 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/23 15:29:51 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void		get_color(int rand)
{
	int const	color[] = {31, 32, 33, 34, 35, 36, 37};
	int const	style[] = {0, 1};

	ft_putstr("\033[");
	ft_putnbr(style[rand % 2]);
	ft_putstr(";");
	ft_putnbr(color[rand % 6]);
	ft_putstr("m");
}

static	int		print_value(t_list *g_env, t_list *l_env, char *key)
{
	t_list		*temp;

	temp = g_env;
	while (temp != NULL)
	{
		if (ft_strcmp(((t_env *)temp->content)->name, key) == 0)
		{
			ft_putstr(((t_env *)temp->content)->value);
			return (0);
		}
		temp = temp->next;
	}
	temp = l_env;
	while (temp != NULL)
	{
		if (ft_strcmp(((t_env *)temp->content)->name, key) == 0)
		{
			ft_putstr(((t_env *)temp->content)->value);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void			print_prompt(int rand, t_list *g_env, t_list *l_env)
{
	get_color(rand);
	if (print_value(g_env, l_env, "PWD") == 0)
	{
		ft_putstr("\033[0m");
		get_color(rand + 2);
		ft_putchar('\n');
		ft_putchar('@');
	}
	print_value(g_env, l_env, "USER");
	ft_putstr("$>");
	ft_putstr("\033[0m");
}
