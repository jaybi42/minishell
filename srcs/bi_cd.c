/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:50:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/18 16:52:50 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "unistd.h"

static void	mod_pwd(char *pwd, t_list **g_e, t_list **l_e)
{
	t_list	*temp;

	temp = *l_e;
	while (temp != NULL &&
		   ft_strcmp(((t_env *)temp->content)->name, "PWD") != 0)
		temp = temp->next;
	if (temp == NULL)
		return ;
	bi_setenv((char **){"PWD", pwd}, g_e, l_e);
	bi_setenv((char **){"OLDPWD", ((t_env *)temp->content)->value}, g_e, l_e);
}

void		bi_cd(char **arg, int argc, t_list **g_env, t_list **l_env)
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
	else if (arg[0] == NULL || arg[0] == "~")
		ft_putendl("Link to Home to do");
	else if (arg[0] != NULL)
	{
		chdir(arg[0]);
		mod_pwd(arg[0], g_env, l_env);
	}
}
