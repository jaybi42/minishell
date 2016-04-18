/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:50:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/18 17:24:19 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "unistd.h"

/*
static int	mod_pwd(char *pwd, t_list **g_e, t_list **l_e)
{
	t_list	*temp;
	int		ret;

	temp = *l_e;
	while (temp != NULL &&
		   ft_strcmp(((t_env *)temp->content)->name, "PWD") != 0)
		temp = temp->next;
	if (temp == NULL)
		return (0);
	ret = bi_setenv((char **){"PWD", pwd}, 2, g_e, l_e);
	if (ret == -1)
		return (-1);
	ret = bi_setenv((char **){"OLDPWD",	((t_env *)temp->content)->value}, 2, g_e, l_e);
	if (ret == -1)
		return (-1);
		}*/

static int	go_home(t_list **g_env, t_list **l_env)
{
/*	t_list  *temp;

	temp = *l_e;
	while (temp != NULL &&
			ft_strcmp(((t_env *)temp->content)->name, "HOME") != 0)
		temp = temp->next;
	if (temp == NULL)
		return (0);
		bi_cd({((t_env *)temp->content)->value, NULL} 1, g_env, l_env);*/
	(void)g_env;
	(void)l_env;
	ft_putendl("No home yet");
	return (0);
}

int			bi_cd(char **arg, int argc, t_list **g_env, t_list **l_env)
{
	if (argc > 2)
		ft_putendl("cd: too many arguments");
	else if (argc > 1)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(arg[0]);
	}
	else if (argc == 1 && access(arg[0], F_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(arg[0]);
	}
	else if (argc == 1 && access(arg[0], X_OK) == -1)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(arg[0]);
	}
	else if (arg[0] == NULL || ft_strcmp(*arg, "~") == 0)
		return (go_home(g_env, l_env));
	else if (arg[0] != NULL)
	{
		chdir(arg[0]);
//		if (mod_pwd(arg[0], g_env, l_env) == -1)
//			return (-1);
	}
	return (0);
}
