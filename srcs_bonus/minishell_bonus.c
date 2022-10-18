/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:00:18 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 02:00:34 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_token	*root;
	t_tree	*head;
	int		(*fp[256])(char *, t_token **, const bool *);
	bool	comp[256];

	if (ac > 1)
		return (printf("%s accept no params\n", ((*av) + 2)), 0);
	g_global.cur = ((root = NULL, g_global.adrs = NULL, &g_global.adrs));
	get_env(env);
	set_signal();
	set_fp_n_comp(fp, comp, 0);
	while (1)
	{
		str = readline("\e[1;32malmond@minishell %\e[0;37m ");
		if (!str)
			the_exit(g_global.status, 1);
		head = token(fp, str, &root, comp);
		if (check_history(str))
			add_history(str);
		free(str);
		if (head)
			cast_node(head);
		root = ((head = NULL, NULL));
	}
}
