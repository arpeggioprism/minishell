/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:13:29 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:10:05 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	ft_unset(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		delete_env(&g_global.env, get_env_node(argv[i]));
	g_global.status = 0;
}
