/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_av.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:11 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/10 18:34:03 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_av		init_av(char *cmd, char *av1, char *av2, int argc)
{
	t_av	av;

	av.all = (char *[]){cmd, av1, av2, NULL};
	av.cmd = cmd;
	av.arg = (char *[]){av1, av2, NULL};
	av.argc = argc;
	return (av);
}
