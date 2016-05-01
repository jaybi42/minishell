/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:52 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/01 14:02:09 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <sys/wait.h>

int			shell(t_list *av_list, t_list **g_env, t_list **l_env)
{
	pid_t	ret;

	while (av_list != NULL)
	{
		if (builtin(((t_av *)av_list->content), g_env, l_env) == 0)
			return (0);
		ret = fork();
		if (ret == 0)
			do_exec(*((t_av *)av_list->content), *g_env, *l_env);
		else if (ret == -1)
			return (print_error(*((t_av *)av_list->content), 6));
		else
			ret = wait(NULL);
		if (ret == 1)
			print_error(AV_INIT("minishell", ((t_av *)av_list->content)->cmd, NULL, 1), 7);
		av_list = av_list->next;
	}
	return (0);
}
