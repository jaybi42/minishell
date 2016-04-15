/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:48:27 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/15 21:50:42 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>

static t_env const	g_initenv[6] = {
	{"PATH", NULL},
	{"HOME", NULL},
	{"USER", NULL},
	{"LOGNAME", NULL},
	{"PWD", NULL},
	{"SHELL", NULL},
};

static char			**get_info(void)
{
	struct stat		stat;
	struct passwd	*pw;
	char			**tab;

	tab = NULL;
	if (lstat(".", &stat) == -1)
		return (NULL);
	if ((pw = getpwuid(stat.st_uid)) == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * 7);
	tab[6] = NULL;
	tab[0] = ft_strdup("/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki");
	tab[1] = ft_strdup(pw->pw_dir);
	tab[2] = ft_strdup(pw->pw_name);
	tab[3] = ft_strdup(pw->pw_name);
	tab[4] = ft_strdup(getwd(NULL));
	tab[5] = ft_strdup(pw->pw_shell);
	return (tab);
}

static void			show_list(t_list *e)
{
	while (e != NULL)
	{
		ft_putstr(((t_env *)e->content)->cmd);
		ft_putchar('=');
		ft_putendl(((t_env *)e->content)->value);
		e = e->next;
	}
}

static int			set_myenv(t_list **e)
{
	char			**tab;
	t_env			env;
	t_list			*tamp;
	int				i;

	i = 0;
	tab = get_info();
	while (i < 6)
	{
		env.cmd = ft_strdup((char *)g_initenv[i].cmd);
		env.value = tab[i];
		tamp = ft_lstnew((void *)&env, sizeof(env));
		if (tamp == NULL)
			return (1);
		ft_lstadd_last(e, tamp);
		i++;
	}
	if (tab != NULL)
	free(tab);
	tab = NULL;
	show_list(*e);
	return (0);
}

static int			set_genv(t_list **e, char **environ)
{
	t_env			env;
	t_list			*tamp;
	int				i;

	i = 0;
	while (environ[i] != NULL)
	{
		i++;
	}
	return (0);
}


int					get_env(t_list **e)
{
    extern char		**environ;

    if (*environ == NULL)
        set_myenv(e);
	while (*environ != NULL)
		set_genv(e, environ);
    return (0);
}
