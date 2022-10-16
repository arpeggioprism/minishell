/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:00:18 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 21:21:49 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_token	*root;
	t_tree	*head;

	if (ac > 1)
		return (printf("%s accept no params\n", ((*av) + 2)), 0);
	g_global.cur = ((root = NULL, g_global.adrs = NULL, &g_global.adrs));
	get_env(env);
	listen();
	while (1)
	{
		str = readline("almond@minishell % ");
		if (!str)
			the_exit(g_global.status);
		head = token(str, &root);
		if (check_history(str))
			add_history(str);
		free(str);
		if (head)
			cast_node(head);
		root = NULL;
		head = NULL;
	}
}
