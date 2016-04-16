/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:39:48 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/01 05:27:33 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quote(t_env *e, char *line)
{
	int i;
	char *buf;

	i = 0;
	while (line[i] != '\0' || line[i] != '\"')
		i++;
	if (line[i] == '\"')
	{
		buf = ft_strnew(i);
		if (buf == NULL)
			return (1);
		ft_strncpy(but, line, i);
		line += i;
	}
	else
	{
		ft_strjoin(e->av_buf, buf);

	}
}

static int	check_line(t_env *e, char *line)
{
	int		i;
	char	*buf;

	i = 0;
	while ((*line == ' ' || *line == '\t') && *line != '\0')
		line++;
	while (*line != '\0')
	{
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && line[i] != '\"')
			i++;
		buf = ft_strnew(i);
		if (buf == NULL)
			return (1);
		ft_strncpy(but, line, i);
		line += i;
		if (*line == '\"')
			check_quote(e, line++);
	}
}

static int	get_argv(t_env *e)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret == 1)
	{
		if (get_next_line(0, &line) == -1)
			return (1);
		if (check_line(e, line) == 0)
			ret = 0;
		else
			ft_putstr("quote?>");
		ft_strdel(&line);
	}
	return (0);
}

int			main(int argc, char **argv, char **env)
{
	t_env	e;

	e.av = FTV_INIT(char*);
	if (argc != 1 && argv[0] != "minishell")
		return (1);
	while (1)
	{
		ft_putstr("$>");
		if (get_argv(e) == 1)
			return (1);
		if (get_env(e) == 1)
			return (1);
		if (get_path(e) == 1)
			return (1);
//		fork;
//		execve;
//		Land program
	}
	return (0);
}
