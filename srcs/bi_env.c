/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:53:06 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/10 18:24:10 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static void		print_env(t_list *env)
{
	while (env != NULL)
	{
		ft_putendl(((t_env *)env->content)->str);
		env = env->next;
	}
}

static int		set_new_arg(char *arg, t_list **g_env, t_list **l_env)
{
	char		*my_arg;
	char		*my_cmd;
	int			i;

	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
		i++;
	if (arg[i] != '=')
		return (1);
	my_cmd = ft_strsub(arg, 0, i);
	my_arg = ft_strchr(arg, '=') + 1;
	bi_setenv(init_av("setenv", my_cmd, my_arg, 2), g_env, l_env);
	if (my_cmd != NULL)
		ft_strdel(&my_cmd);
	return (0);
}

static int		parse_env(t_av av, t_list **g_env, t_list **l_env)
{
	int			i;

	i = -1;
	while (++i < av.argc)
	{
		if (ft_strncmp("-i", av.arg[i], 2) == 0)
			ft_lstdel(g_env, free_env);
		else if (ft_strncmp("-u", av.arg[i], 2) == 0)
			bi_unsetenv(init_av(NULL, av.arg[++i], NULL, 1), g_env, l_env);
		else
			break ;
	}
	while (i < av.argc && set_new_arg(*(av.arg + i), g_env, l_env) == 0)
		i++;
	return (i);
}

int				bi_env(t_av av, t_list **g_env, t_list **l_env)
{
	int			ret;
	t_av		new_av;

	ret = fork();
	if (ret == 0)
	{
		ret = parse_env(av, g_env, l_env);
		new_av.argc = av.argc - ret;
		if (new_av.argc >= 1)
		{
			new_av.cmd = av.arg[ret];
			new_av.arg = av.arg + ret + 1;
			do_exec(new_av, *g_env, *l_env);
		}
		else
			print_env(*g_env);
		bi_exit(init_av(NULL, NULL, NULL, 0), NULL, NULL);
	}
	else if (ret == -1)
		return (print_error(av, 6));
	else
		ret = wait(NULL);
	return (0);
}
