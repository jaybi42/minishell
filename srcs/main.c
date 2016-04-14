/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:36:17 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/14 16:25:36 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env(char **env, t_list **e)
{

}

static int	get_argv(t_list **av, char *line)
{
	t_av	av_t;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = ft_strsplit(line, ';');
	if (tab == NULL)
		return
	while (tab[i] != NULL)
	{
		while (tab[i] != NULL && ft_strchr(tab[i], ';') != NULL)
		av_t.cmd = tab[i];
		if (av == NULL)
			ft_lstnew();
		tab[i]
		i++;
	}
	return (0);
}

static int	do_shell(t_list *av, t_list **e)
{
	int		ret;

	ret = 0;
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
	t_list	*av;
	char	*line;
	int		ret;

	(void)**argv;
    if (argc != 1)
        return (1);
    while (1)
    {
        ft_putstr("$>");
        if (get_env(env, &e) == 1)
            return (1);
		if (get_next_line(0, &line) < 0)
			return (1);
        if (get_argv(&av, line) == NULL)
            continue ;
		if (do_shell(av, &e) == 1)
			return (1);
    }
    return (0);
}
