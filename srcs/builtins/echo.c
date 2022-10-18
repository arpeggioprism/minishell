/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:12:11 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 03:08:13 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	new_line(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] != 'n')
			return (0);
	return (1);
}

int	get_echo_flag(int flag)
{
	if (flag == 0 || flag == -2)
		return (-2);
	else
		return (-1);
}

int	ft_echo(char **argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (argv[++i])
	{
		if (flag >= 0 && argv[i][0] && argv[i][0] == '-' && argv[i][1])
		{
			if (new_line(argv[i]))
			{
				flag = -2;
				continue ;
			}
		}
		else
			flag = get_echo_flag(flag);
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putstr_fd(" ", 1);
	}
	if (flag != -2)
		ft_putstr_fd("\n", 1);
	g_global.status = 0;
	return (0);
}
