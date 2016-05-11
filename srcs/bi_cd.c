/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:50:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/11 14:05:47 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "unistd.h"

static int	mod_pwd(char *pwd, t_list **g_e, t_list **l_e)
{
	t_list	*temp;
	t_env	*env;

	temp = *g_e;
	while (temp != NULL)
	{
		env = ((t_env *)temp->content);
		if (ft_strcmp(env->name, "PWD") == 0)
			break ;
		temp = temp->next;
	}
	if (temp != NULL && env->value != NULL)
		bi_setenv(INIT_AV("setenv", "OLDPWD", env->value, 2), g_e, l_e);
	else
		bi_setenv(INIT_AV("setenv", "PWD", pwd, 2), g_e, l_e);
	return (0);
}

static int	go_back(t_list **g_e, t_list **l_e)
{
	t_list  *temp;

	temp = *g_e;
	while (temp != NULL)
	{
		if (ft_strcmp(((t_env *)temp->content)->name, "OLDPWD") == 0)
			break ;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	bi_cd(INIT_AV(NULL, ((t_env *)temp->content)->value, NULL, 1), g_e, l_e);
	return (0);
}

static int	go_home(t_list **g_e, t_list **l_e)
{
	t_list  *temp;

	temp = *l_e;
	while (temp != NULL)
	{
		if (ft_strcmp(((t_env *)temp->content)->name, "HOME") == 0)
			break ;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	bi_cd(INIT_AV(NULL, ((t_env *)temp->content)->value, NULL, 1), g_e, l_e);
	return (0);
}

int			bi_cd(t_av av, t_list **g_env, t_list **l_env)
{
	if (av.argc > 2)
		return (print_error(av, 0));
	if (av.argc > 1)
		return (print_error(av, 1));
	if (*av.arg == NULL || ft_strcmp(*av.arg, "~") == 0)
		return (go_home(g_env, l_env));
	if (av.argc == 1 && ft_strcmp(*av.arg, "-") == 0)
		return (go_back(g_env, l_env));
	if (av.argc == 1 && access(*av.arg, F_OK) == -1)
		return (print_error(av, 2));
	if (av.argc == 1 && access(*av.arg, X_OK) == -1)
		return (print_error(av, 3));
	if (*av.arg != NULL)
	{
		chdir(*av.arg);
		return (mod_pwd(*av.arg, g_env, l_env));
	}
	return (0);
}
