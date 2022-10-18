/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:12:52 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/18 19:44:25 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	the_exit(int status, int d_flag)
{
	if (d_flag == 0)
		printf("exit\n");
	else if (d_flag == 1)
	{
		printf("\033[1A");
		printf("\033[18C");
		printf(" exit\n");
	}
	ft_collect(&g_global.adrs, g_global.adrs, 1);
	rl_clear_history();
	exit(status);
}

int	ft_exit(char **argv)
{
	if (!argv[1])
		the_exit(g_global.status, 0);
	else if (argv[1] && !ft_isdigit(argv[1]))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		the_exit(255, 3);
	}
	else if (argv[1] && ft_isdigit(argv[1]))
	{
		if (!argv[2])
			the_exit(ft_atoi(argv[1]), 0);
		else if (argv[2])
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_global.status = 1;
			return (0);
		}
	}
	return (0);
}
