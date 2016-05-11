/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:08:29 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/11 11:30:26 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_error const	g_print[8] = {
	{1, ": too many arguments.", 0},
	{1, ": string not in pwd: ", 1},
	{1, ": no such file or directory: ", 1},
	{1, ": permission denied: ", 1},
	{1, ": Variable name must contain alphanumeric characters.", 0},
	{1, ": Variable name must begin with a letter.", 0},
	{0, "Fork is fucked.", 0},
	{1, ": command not found: ", 1},
};

int		print_error(t_av av, int error)
{
	if (g_print[error].cmd == 1)
		ft_putstr(av.cmd);
	ft_putstr(g_print[error].str);
	if (g_print[error].arg == 1)
		ft_putstr(av.arg[0]);
	ft_putchar('\n');
	return (1);
}
