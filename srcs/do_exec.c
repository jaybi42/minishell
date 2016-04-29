/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:57:26 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/29 17:28:53 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static void	ft_print_tab(char **tab, char *name)
{
	int i = 0;

	ft_putstr("----- ");
	ft_putstr(name);
	ft_putendl(" -----");
	while (tab[i] != NULL)
	{
		ft_putnbr(i);
		ft_putstr(" : [");
		ft_putstr(tab[i]);
		ft_putstr("]\n");
		i++;
	}
	ft_putendl("---------------");
}

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

static char **convert_env(t_list *env)
{
	t_list	*begin;
	char	**tab;
	int		i;

	i = 0;
	begin = env;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		return (NULL);
	tab[i--] = NULL;
	while (env != NULL)
	{
		tab[i--] = ft_strdup(((t_env *)env->content)->str);
		env = env->next;
	}
	return (tab);
}

static void exec_path(char **arg, char **path, char **env)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(path[i], X_OK) != -1 && execve(path[i], arg, env) == 0)
			return ;
		i++;
	}
}

static char	**get_allpath(char *cmd, char *path)
{
	char	**temp;
	char	**allpath;
	int		i;

	i = -1;
	temp = ft_strsplit(path, ':');
	allpath = (char **)malloc(sizeof(char *) * (ft_tablen(temp) + 1));
	while (temp[++i] != NULL)
		allpath[i] = ft_strjoin(temp[i], "/");
	allpath[i] = NULL;
	ft_tabdel(temp);
	temp = (char **)malloc(sizeof(char *) * (ft_tablen(allpath ) + 1));
	i = -1;
	while (allpath[++i] != NULL)
		temp[i] = ft_strjoin(allpath[i], cmd);
	temp[i] = NULL;
	ft_tabdel(allpath);
	return (temp);
}

int			do_exec(t_av av, t_list *g_env, t_list *l_env)
{
	char	**env;
	char	**path;
	char	*str;
	pid_t	ret;

	ret = fork();
	if (ret > 0)
		ret = wait(NULL);
	else if (ret == -1)
		return (print_error(av, 6));
	else
	{
		env = convert_env(g_env);
		if (env == NULL)
			env = convert_env(l_env);
		str = get_path(g_env);
		if (str == NULL)
			str = get_path(l_env);
		if (execve(av.cmd, av.arg, env) == -1)
		{
			path = get_allpath(av.cmd, str);
			exec_path(av.arg, path, env);
			ft_tabdel(path);
		}
		ft_tabdel(env);
	}
	return (0);
}
