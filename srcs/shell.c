/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:52 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/22 18:42:26 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

static char	*get_path(t_list *env)
{
	while (env != NULL)
	{
		if (ft_strcmp(((t_env *)env->content)->name, "PATH") == 0)
			return (((t_env *)env->content)->value);
		env = env->next;
	}
	return (NULL);
}

static char	**convert_env(t_list *env)
{
	char	**tab;
	int		i;
	bool	moche;

	moche = 0;
	i = 0;
	while (env != NULL)
	{
		if (ft_strcmp(((t_env *)env->content)->name, "PATH") == 0)
			moche = 1;
		i++;
		env = env->next;
	}
	if (moche == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab[i--] = NULL;
	while (env != NULL)
	{
		tab[i--] = ((t_env *)env->content)->str;
		env = env->next;
	}
	return (tab);
}

static void	exec_path(char **arg, char **path, char **env)
{
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		if (execve(path[i], arg, env) == 0)
			return ;
		i++;
	}
}

static void do_exec(t_av *av, t_list *g_env, t_list *l_env)
{
	char	**env;
	char	**path;
	char	*str;

	env = convert_env(g_env);
	if (env == NULL)
		env = convert_env(l_env);
	str = get_path(g_env);
	if (str == NULL)
		str = get_path(l_env);
	if (execve(av->cmd, av->arg, env) == -1)
	{
		path = ft_strsplit(str, ':');
		exec_path(av->arg, path, env);
	}
//	ft_tabdel(env);
}

int			shell(t_list *av_list, t_list **g_env, t_list **l_env)
{
	pid_t	ret;

	while (av_list != NULL)
	{
		if (builtin(((t_av *)av_list->content), g_env, l_env) == 0)
			return (0);
		ret = fork();
		if (ret == -1)
			return (0);
		do_exec(((t_av *)av_list->content), *g_env, *l_env);
		av_list = av_list->next;
	}
	return (0);
}
