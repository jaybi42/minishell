/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/17 19:29:07 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void show_list(t_list *av)
{
	int i = 0;
	t_av *avs;

    if (av == NULL)
        ft_putendl("list NULL");
    while (av != NULL)
    {
		avs = (t_av *)av->content;
		ft_putchar('[');
        ft_putstr(avs->cmd);
        ft_putchar(']');
        ft_putstr("    ");
        if (avs->arg != NULL)
        {
            while (avs->arg[i] != NULL)
            {
                ft_putchar('[');
                ft_putstr(avs->arg[i]);
                if (avs->arg[++i] != NULL)
                    ft_putstr("]  ");
                else
                    ft_putendl("]");
            }
        }
        else
            ft_putendl("[]");
        av = av->next;
    }
}

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
		show_list(av);
		if (shell(av, &g_env, &l_env) == 1)
			return (1);
		ft_lstdel(&av, free_av);
	}
	return (0);
}
