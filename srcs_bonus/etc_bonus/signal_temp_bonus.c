/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_temp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:12:10 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/18 19:50:34 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	handler2(int sig)
{
	if (sig != SIGINT || !g_global.running)
		return ;
	if (g_global.running)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		printf("^C\n");
	}
}

void	handler3(int sig)
{
	if (sig != SIGQUIT || !g_global.running)
		return ;
	if (g_global.running)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		printf("^\\Quit: 3\n");
	}
}

void	change_signal(void)
{
	signal(SIGINT, &handler2);
	signal(SIGQUIT, &handler3);
}
