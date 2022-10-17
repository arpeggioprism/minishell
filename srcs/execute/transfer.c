/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:16:05 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:32 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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