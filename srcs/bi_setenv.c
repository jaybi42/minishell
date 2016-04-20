/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 13:28:44 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/20 13:37:19 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void set_arg(char *name, char *value, t_list **g_env)
{
	t_env	env;
	t_list	*new_link;
	char	*temp;

	temp = ft_strjoin(name, "=");
	if (temp == NULL)
		return ;
	env.str = ft_strjoin(temp, value);
	ft_strdel(&temp);
	if (env.str == NULL)
		return ;
	env.name = ft_strdup(name);
	env.value = ft_strdup(value);
	new_link = ft_lstnew((void *)&env, sizeof(t_env));
	ft_lstadd_last(g_env, new_link);
}

int		bi_setenv(t_av *av, t_list **g_env, t_list **l_env)
{
	int	i;

	i = 0;
	(void)l_env;
	if (av->argc == 0)
		bi_env(av, g_env, l_env);
	if (av->argc > 2)
		print_error(av, 0);
	else if (av->argc >= 1 && ft_isalpha(*av->arg[0]) == 0)
		print_error(av, 5);
	else if (av->argc >= 1 && ft_strisalnum(*av->arg) == 0)
		print_error(av, 4);
	else if (av->argc == 1)
		set_arg(*av->arg, "Unknown", g_env);
	else if (av->argc == 2)
		set_arg(av->arg[0], av->arg[1], g_env);
	return (0);
}
