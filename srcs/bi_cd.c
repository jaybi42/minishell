/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:50:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/21 12:43:41 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "unistd.h"

static int	mod_pwd(char *pwd, t_list **g_e, t_list **l_e)
{
//	t_list	*temp;
//	t_av	*av;
	int		ret;
	t_av const av[1] = {
		{"setenv", ((char **){"PWD", pwd}), 2}
		};

	ret = bi_setenv((t_av *)av, g_e, l_e);
	return (ret);
/*	temp = *l_e;
	while (temp != NULL &&
		   ft_strcmp(((t_env *)temp->content)->name, "PWD") != 0)
		temp = temp->next;
	if (temp == NULL)
		return (0);
	av->argc = 2;
	av->arg[0] = ft_strdup("PWD");
	av->argv[1] = ft_strdup(pwd);
	av->cmd = ft_strdup("setenv");
	if (ret == -1)
		return (-1);
	ret = bi_setenv((char **){"OLDPWD",	((t_env *)temp->content)->value}, 2, g_e, l_e);
	if (ret == -1)
	return (-1);*/
}

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

int			bi_cd(t_av *av, t_list **g_env, t_list **l_env)
{
	if (av->argc > 2)
		return (print_error(av, 0));
	else if (av->argc > 1)
		return (print_error(av, 1));
	else if (av->argc == 1 && access(*av->arg, F_OK) == -1)
		return (print_error(av, 2));
	else if (av->argc == 1 && access(*av->arg, X_OK) == -1)
		return (print_error(av, 3));
	else if (*av->arg == NULL || ft_strcmp(*av->arg, "~") == 0)
		return (go_home(g_env, l_env));
	else if (*av->arg != NULL)
	{
		chdir(*av->arg);
//		if (mod_pwd(av->arg, g_env, l_env) == -1)
//			return (-1);
	}
	return (0);
}
