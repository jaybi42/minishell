/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/16 19:10:59 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     	main(void)
{
	t_list	*l_env;
	t_list	*g_env;
	t_list	*av;
	char	*line;

	while (1)
	{
		ft_putstr("$>");
		if (get_env(&g_env, &l_env) == 1)
			return (1);
		if (read_i(&av) == 1)
			continue ;
//		if (shell(av, &g_env, &l_env) == 1)
//			return (1);
		ft_lstdel(&av, free_av);
	}
	return (0);
}
