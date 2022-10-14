/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:12:00 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/14 19:12:06 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_dir(char **argv, int s, char *old_cur)
{
	char	buf[255];
	char	*cur;
	t_env	*node;

	if (s < 0)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_global.status = 1;
	}
	else
	{
		node = get_env_node("OLDPWD");
		if (node)
			node->value = old_cur;
		node = get_env_node("PWD");
		getcwd(buf, 255);
		cur = ft_strdup(buf);
		if (node)
			node->value = cur;
		g_global.status = 0;
	}
}

void	ft_cd(char **argv)
{
	char	*home;
	char	buf[4096];
	char	*cur;

	getcwd(buf, 4096);
	cur = ft_strdup(buf);
	if (!argv[1])
	{
		home = get_env_value("HOME");
		if (!home)
		{
			ft_putstr_fd("bash: cd: HOME not set", 2);
			g_global.status = 1;
			return ;
		}
		argv[1] = home;
	}
	check_dir(argv, chdir((const char *)argv[1]), cur);
}
