/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/15 13:49:55 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "stdlib.h"//

static int	get_env(char **env, t_list **e)
{
	extern char **environ;

	(void)**e;
	(void)**env;
	if (environ == NULL)
		exit(0);
	return (0);
}

static int	get_argv(t_av *av, char *line)
{
	int		i;

	i = 0;
	av->av_l = ft_strsplit(line, ';');
	if (av->av_l == NULL)
		return (0);
	while (av->av_l[i] != NULL)
	{
		printf("str[%i]: [%s]\n", i, av->av_l[i]);
		i++;
	}
	ft_putchar('\n');
	av->cmd = i;
	return (0);
}

static int	do_shell(t_av av, t_list **e)
{
	int		ret;

	ret = 0;
	(void)**e;
	(void)av;
/*	while (ret > 0)
	{
		if (get_path(e) == -1)
            return (-1);
      fork;
      execve;
      Land program;
	  }*/
	return (0);
}


int         main(int argc, char **argv, char **env)
{
	t_list	*e;
	t_av	av;
	char	*line;

	(void)argc;
	(void)**argv;
    while (1)
    {
        ft_putstr("$>");
        if (get_env(env, &e) == 1)
            return (1);
		line = NULL;
		while (line == NULL)
		{
			if (get_next_line(0, &line) < 0)
				return (1);
		}
        if (get_argv(&av, line) == 1)
            continue ;
		if (do_shell(av, &e) == 1)
			return (1);
//		free_av(&av);
    }
    return (0);
}
