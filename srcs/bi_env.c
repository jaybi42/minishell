/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:53:06 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/25 17:54:01 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_env(t_list *env)
{
	while (env != NULL)
	{
		ft_putendl(((t_env *)env->content)->str);
		env = env->next;
	}
}

static void		set_newarg(t_av av, t_list **n_env, t_list **l_env)
{
	char		*my_arg;
	char		*my_cmd;
	int			i;

	i = 0;
	while (av.arg[0][i] != '\0' && av.arg[0][i] != '=')
		i++;
	my_cmd = ft_strsub(*av.arg, 0, i);
	my_arg = ft_strchr(*av.arg, '=') + 1;
	bi_setenv(AV_INIT("setenv", my_cmd, my_arg, 2), n_env, l_env);
	if (my_cmd != NULL)
		ft_strdel(&my_cmd);
}

static t_list	*get_new_env(t_av av, t_list **g_env, t_list **l_env)
{
	t_list	*new_list;

	new_list = *g_env;
	set_newarg(av, &new_list, l_env);
	return (new_list);
}

int				bi_env(t_av av, t_list **g_env, t_list **l_env)
{
	t_list		*n_env;

	n_env = NULL;
	if (av.argc != 0)
		n_env = get_new_env(av, g_env, l_env);
	if (av.argc > 1)
		do_exec(av, n_env, *l_env);
	else if (av.argc == 1)
	{
		print_env(n_env);
		if (n_env != NULL)
			ft_lstdel(&n_env, free_env);
	}
	else
		print_env(*g_env);
	return (0);
}
