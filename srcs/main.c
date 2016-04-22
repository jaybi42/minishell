/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/22 16:17:55 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <time.h>

int				main(void)
{
	t_list		*l_env;
	t_list		*g_env;
	t_list		*av;
	int			random_i;

	srand(time(NULL));
	random_i = (int)rand();
	ft_putendl(ft_itoa(random_i));
	if (get_env(&g_env, &l_env) == 1)
		return (1);
	while (1)
	{
		print_prompt(random_i, g_env, l_env);
		if (read_i(&av) == 1)
			continue ;
		if (shell(av, &g_env, &l_env) == 1)
			return (1);
		ft_lstdel(&av, free_av);
	}
	return (0);
}
