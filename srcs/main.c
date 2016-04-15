/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/15 21:16:28 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	split_cmd(t_av *av, char *line)
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

static int	do_shell(t_av av, t_list **e)
{
	int		ret;

	(void)av;
	(void)**e;
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


int         main(void)
{
	t_list	*e;
	t_av	av;
	char	*line;

	e = NULL;
    while (1)
    {
        ft_putstr("$>");
        if (get_env(&e) == 1)
            return (1);
		line = NULL;
		while (line == NULL)
		{
			if (get_next_line(0, &line) < 0)
				return (1);
		}
        if (split_cmd(&av, line) == 1)
            continue ;
		if (do_shell(av, &e) == 1)
			return (1);
//		free_av(&av);
    }
    return (0);
}
