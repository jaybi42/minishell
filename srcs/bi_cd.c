/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:50:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/17 15:10:18 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "unistd.h"

void		bi_cd(char **av)
{
	if (av[0] != NULL && av[1] != NULL && av[2] != NULL)
		ft_putendl("cd: too many arguments ");
	else if (av[0] != NULL && av[1] != NULL)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(av[0]);
	}
	else if (av[0] != NULL && access(av[0], X_OK) == -1)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(av[0]);
	}
	else if (av[0] == NULL || av[0] == "~")
	{
		ft_putendl("Link to Home to do");
	}
	else if (av[0] != NULL )
	{
		if (chdir(av[0]) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(av[0]);
		}
	}
}
