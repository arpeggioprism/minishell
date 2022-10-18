/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:16:05 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 04:08:20 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

char	**transfer(t_command *root)
{
	int		i;
	int		n;
	char	**argv;

	i = -1;
	n = cmdlstsize(root);
	argv = ft_malloc(g_global.cur, (n + 1) * sizeof(char *), 1);
	while (root)
	{
		argv[++i] = root->content;
		root = root->next;
	}
	argv[n] = NULL;
	return (argv);
}

bool	is_slash(char *argv)
{
	unsigned int	i;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	while (i < sizeof(argv) - 1)
		if (argv[i++] == '/')
			cnt++;
	if (cnt == 0)
		ft_putstr_fd(": command not found\n", 1);
	else if (argv[i] == '/')
		ft_putstr_fd(": Not a directory\n", 1);
	else if (argv[0] != '/')
	{
		ft_putstr_fd(": No such file or directory\n", 1);
		return (0);
	}
	else if (argv[ft_strlen(argv) - 1] != '/')
	{
		ft_putstr_fd(": Not a directory\n", 1);
		return (0);
	}
	else
		ft_putstr_fd(": command not found\n", 1);
	return (0);
}
