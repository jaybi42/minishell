/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:53:06 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/18 18:47:23 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			bi_setenv(char **av, int argc, t_list **g_env, t_list **l_env)
{
	(void)av;
	(void)argc;
	(void)g_env;
	(void)l_env;
    return (0);
}

static void	show_env(t_list *env)
{
	ft_putendl("--------START--------");
	while (env != NULL)
	{
		ft_putendl(((t_env *)env->content)->str);
		env = env->next;
	}
	ft_putendl("--------END--------");
}

int			bi_unsetenv(char **av, int argc, t_list **g_env, t_list **l_env)
{
	t_list	*prev;
	t_list	*temp;

	(void)argc;
	(void)l_env;
	if (g_env == NULL || av[0] == NULL)
		return (0);
	prev = *g_env;
	if (ft_strstr(((t_env *)prev->content)->str, av[0]) != NULL)
	{
		g_env = &prev->next;
		ft_lstdelone(&prev, free_env);
		return (0);
	}
	show_env(temp);
	temp = prev->next;
	while (temp != NULL &&
		   ft_strstr(((t_env *)temp->content)->str, av[0]) == NULL)
	{
		prev = prev->next;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	prev = temp->next;
	ft_lstdelone(&temp, free_env);
	show_env(*g_env);
    return (0);
}

int			bi_env(char **av, int argc, t_list **g_env, t_list **l_env)
{
	(void)av;
	(void)argc;
	(void)g_env;
	(void)l_env;
    return (0);
}
