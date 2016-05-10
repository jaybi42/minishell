/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/10 15:33:29 by jguthert         ###   ########.fr       */
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
	if (get_env(&g_env, &l_env) == 1)
		return (1);
	while (1)
	{
		print_prompt((int)nbr, g_env, l_env);
		if (read_i(&av) == 1)
			continue ;
		if (shell(av, &g_env, &l_env) == 1)
			return (1);
		ft_lstdel(&av, free_av);
	}
	return (0);
}
