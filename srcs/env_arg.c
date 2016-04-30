/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 17:41:55 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/30 18:33:22 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

static int		set_newarg(char *arg, t_list **g_env, t_list **l_env)
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
	bi_setenv(AV_INIT("setenv", my_cmd, my_arg, 2), g_env, l_env);
	if (my_cmd != NULL)
		ft_strdel(&my_cmd);
	return (0);
}

int				env_arg(char **arg, t_list **g_env, t_list **l_env)
{

	return (0);
}
