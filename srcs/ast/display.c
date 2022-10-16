/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:49 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:22 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	display_nodetree(t_command *root)
{
	t_command	*temp;

	temp = root;
	if (!root)
		printf("List is empty");
	else
	{
		temp = root;
		while (temp)
		{
			printf("[%s] ", temp->content);
			temp = temp->next;
		}
	}
}
