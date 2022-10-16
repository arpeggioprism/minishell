/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_connecters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:06:57 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:21 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*get_block(t_token **head)
{
	t_tree	*ret;
	t_token	*tmp;
	t_tree	*left;
	t_tree	*right;

	ret = get_pipe(head);
	while (*head)
	{
		if ((*head)->type >= 12 && (*head)->type <= 13)
		{
			tmp = *head;
			*head = get_right(*head);
			left = (t_tree *)ret;
			right = (t_tree *)get_pipe(head);
			ret = (t_tree *)get_wp(get_type(tmp), left, right);
		}
		else
			break ;
	}
	return ((t_tree *)ret);
}

t_tree	*get_pipe(t_token **head)
{
	t_tree	*ret;
	t_token	*tmp;
	t_tree	*left;
	t_tree	*right;

	ret = get_command(head);
	while (*head)
	{
		if ((*head)->type == 14)
		{
			tmp = *head;
			*head = get_right(*head);
			left = ret;
			right = get_command(head);
			ret = get_wp(get_type(tmp), left, right);
		}
		else
			break ;
	}
	return ((t_tree *)ret);
}
