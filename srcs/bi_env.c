/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:53:06 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/30 18:32:39 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static t_env_opt const	g_env_option[2] = {
	{"-i", env_i, 1},
	{"-u", env_u, 2},
};

static void		print_env(t_list *env)
{
	while (env != NULL)
	{
		ft_putendl(((t_env *)env->content)->str);
		env = env->next;
	}
}

static void		remake_av(t_av *av, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
	{
		if (av->arg[i] != NULL)
			ft_strdel(av->arg[i]);
		i++;
	}
	i = -1;
	while (++i < av->argc - nbr)
		av->arg[i] = av->arg[i + nbr];
	while (i < av->argc)
		av->arg[i++] = NULL;
	av->argc -= nbr;
}

static void		env_i(char **arg, t_list **g_env, t_list **l_env)
{
	(void)arg;
	ft_listdel(g_env, free_env);
	return (0);
}

static int		parse_env(t_av av, t_list **g_env, t_list **l_env)
{
	int		i;
	int		total;

	total = 0;
	i = 0;
	while (i < 2 && total != av->argc)
	{
		if (ft_strncmp(g_env_option[i].key, av.arg[total], 2) == 0)
		{
			g_env_option[i].value(av->arg + total, g_env, l_env);
			total += g_env_option[i].nbr;
			i = 0;
		}
		else
			i++;
	}
	while (env_arg(av->arg + total, g_env, l_env) == 1)
		total++;
//	if (av->argc - total == 1)
//		do_exec(av, *g_env, *l_env);
//	else
	print_env(g_env);
	return (0);
}

int				bi_env(t_av av, t_list **g_env, t_list **l_env)
{
	int			ret;

    ret = fork();
    if (ret == 0)
    {
		if (av.argc == 0)
			print_env(*g_env);
		else
			parse_env(av, g_env, l_env);
		bi_exit(AV_INIT(NULL, NULL, NULL, 0), NULL, NULL);
	}
    else if (ret == -1)
        return (print_error(av, 6));
    else
		ret = wait(NULL);
	return (0);
}
