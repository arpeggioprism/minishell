/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:00:18 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/18 23:50:32 by jiwkwon          ###   ########.fr       */
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
	set_signal();
	while (1)
	{
		str = readline("\e[1;34malmond@minishell %\e[0;37m ");
		if (!str)
			the_exit(g_global.status, 1);
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
