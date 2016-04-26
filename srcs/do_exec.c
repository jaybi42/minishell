/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:57:26 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/26 14:13:45 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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
	bool	moche;

	moche = 0;
	i = 0;
	begin = env;
	while (begin != NULL)
	{
		if (ft_strcmp(((t_env *)begin->content)->name, "PATH") == 0)
			moche = 1;
		i++;
		begin = begin->next;
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

static void exec_path(char **arg, char **path, char **env)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		ft_putendl(path[i]);
		if (access(path[i], X_OK) != -1 && execve(path[i], arg, env) == 0)
			return ;
		i++;
	}
}

static char	**get_allpath(char *cmd, char *path)
{
	char	**temp;
	char	**allpath;

	temp = ft_strsplit(str, ':');

}

int			do_exec(t_av av, t_list *g_env, t_list *l_env)
{
	char	**env;
	char	**path;
	char	*str;
	pid_t	ret;
	int		loc;

	if ((ret = fork()) == -1)
		return (print_error(av, 6));
	if (ret > 0)
		ret = wait(&loc);
	if (ret == -1)
		return (-1);
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
	return (0);
}
