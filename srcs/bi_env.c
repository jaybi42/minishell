/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:53:06 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/19 19:27:35 by jguthert         ###   ########.fr       */
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

static void	unset_link(t_list **g_env, t_list *link)
{
	t_list	*prev;

	prev = *g_env;
	if (*g_env == link)
	{
		g_env = &prev->next;
		ft_lstdelone(g_env, free_env);
		return ;
	}
	while (prev->next != link)
		prev = prev->next;
	prev = link->next;
	ft_lstdelone(&link, free_env);
	show_env(*g_env);
}

/*
static void	set_arg()
{

}
*/
int			bi_setenv(char **av, int argc, t_list **g_env, t_list **l_env)
{
	int		i;

	i = 0;
	(void)l_env;
	if (argc > 2)
	{
//		print_error(av, 0);
		return (0);
	}
	if (argc == 1 && ft_strstr(av[0], ((t_env *)link->content)->name) != NULL)
		set_arg(av[0], ft_strchr(av[0], '='));
	else if (argc == 2 && ft_strstr(av[0], ((t_env *)link->content)->name) != NULL)
		set_arg(av[0], av[1]);
    return (0);
}

int			bi_unsetenv(char **av, int argc, t_list **g_env, t_list **l_env)
{
	t_list	*link;

	(void)argc;
	(void)l_env;
	if (g_env == NULL || av[0] == NULL)
		return (0);
	link = *g_env;
	while (link != NULL)
	{
		if (ft_strstr(((t_env *)link->content)->str, av[0]) != NULL)
		{
			unset_link(g_env, link);
			show_env(*g_env);
			return (0);
		}
		link = link->next;
	}
    return (0);
}

int			bi_env(char **av, int argc, t_list **g_env, t_list **l_env)
{
	t_list	*c_env;

	c_env = *g_env;
//	if (argc != 0)
//		bi_setenv(*av, 1, &c_env, l_env);
//	*av++;
//	if (argc > 1)
//		fonction_execve(av);
	while (c_env != NULL)
	{
		ft_putendl(((t_env *)c_env->content)->str);
		c_env = c_env->next;
	}
	return (0);
}
