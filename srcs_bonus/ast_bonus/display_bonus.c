/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:49 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:10:23 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

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
