/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/16 13:42:04 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	split_line(t_av *av, char *line)
{
	int		i;
	char	*temp;

	i = 0;
	av->av_l = ft_strsplit(line, ';');
	if (av->av_l == NULL)
		return (1);
	while (av->av_l[i] != NULL)
	{
		temp = ft_strtrim(av->av_l[i]);
		ft_strdel(&av->av_l[i]);
		av->av_l[i] = temp;
		i++;
	}
	av->cmd = i;
	return (0);
}

static int	do_shell(t_av av, t_list **g_env, t_list **l_env)
{
	int		ret;

	(void)av;
	(void)**g_env;
	(void)**l_env;
	ret = 0;
/*	(void)**e;
	(void)av;
	while (ret > 0)
	{
		if (get_builtin(e) == -1)
            return (-1);
      fork;
      execve;
      Land program;
	  }*/
	return (0);
}

static void	free_av(t_av *av)
{
}

int         main(void)
{
	t_list	*l_env;
	t_list	*g_env;
	t_av	av;
	char	*line;

    while (1)
    {
        ft_putstr("$>");
        if (get_env(&g_env, &l_env) == 1)
            return (1);
		line = NULL;
		while (line == NULL)
		{
			if (get_next_line(0, &line) < 0)
				return (1);
		}
        if (split_line(&av, line) == 1)
            continue ;
		if (do_shell(av, &g_env, &l_env) == 1)
			return (1);
		while (av.cmd-- >= 0)
			ft_strdel(&av.av_l[cmd]);
    }
    return (0);
}
