/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 12:25:31 by jguthert         ###   ########.fr       */
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
	uint64_t	nbr;

	srand(time(NULL));
	nbr = rand() % 2147483648;
	if (init_env(&g_env, &l_env) == 1)
		return (1);
	catch_sig(nbr, g_env, l_env);
	while (1)
	{
		print_prompt(nbr, g_env, l_env);
		if (read_init(&av) == 1)
			continue ;
		if (shell(av, &g_env, &l_env) == 1)
			return (1);
		ft_lstdel(&av, free_av);
	}
	return (0);
}
