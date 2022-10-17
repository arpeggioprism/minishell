/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:15:53 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 22:34:33 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	handler(int sig)
{
	if (g_global.running)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		return ;
	}
	g_global.status = 128 + sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handler2(int sig)
{
	if (!g_global.running)
		return ;
	if (g_global.running)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		printf("Quit: 3\n");
		return ;
	}
	(void)sig;
}

void	listen(void)
{
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sigmodi(void)
{
	signal(SIGQUIT, &handler2);
}

void	sigreset(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
