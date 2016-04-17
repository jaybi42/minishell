/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:07:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/17 19:37:29 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_argv(t_av *argv, char *str)
{
	int		j;
	int		k;

	j = 0;
	ft_bzero(argv,sizeof(t_av));
	while (ft_isblank(str[j]) == 1 && str[j] != '\0')
		j++;
	k = j;
	while (ft_isspace(str[k]) == 0 && str[k] != '\0')
		k++;
	argv->cmd = ft_strsub(str, j, k - j);
	argv->arg = ft_strsplit_blank(str + k);
}

static int	split_line(t_list **av, char *line)
{
	t_list	*temp;
	t_av	argv;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ';');
	if (tab == NULL)
		return (1);
	while (tab[i] != NULL)
	{
		fill_argv(&argv, tab[i]);
		temp = ft_lstnew((void *)&argv, sizeof(t_av));
		if (temp == NULL)
			return (1);
		ft_lstadd_last(av, temp);
		i++;
	}
	return (0);
}

int			read_i(t_list **av)
{
	char	*line;

	*av = NULL;
	line = NULL;
	while (line == NULL)
	{
		if (get_next_line(0, &line) < 0)
			return (1);
	}
	return (split_line(av, line));
}
