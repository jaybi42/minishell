/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:08:23 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/17 19:29:51 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void		free_av(void *content, size_t size)
{
	t_av	*av;
	char	**argv;
	char	*cmd;
	int i = 0;

	(void)size;
	av = (t_av *)content;
	if (av != NULL)
	{
		argv = (char **)av->arg;
		cmd = (char *)av->cmd;
		if (argv != NULL)
		{
			while (*argv != NULL)
			{
				ft_strdel(&*argv);
				*argv++;
			}
			ft_strdel(argv);
		}
		if (cmd != NULL)
			ft_strdel(&cmd);
		free(content);
		content = NULL;
	}
}
