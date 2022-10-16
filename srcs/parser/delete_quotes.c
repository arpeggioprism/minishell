/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:18:28 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:34 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*link_nodes(t_token **root, t_token *deleted)
{
	t_token	*tmp;

	if (!deleted->prev)
	{
		*root = deleted->next;
		(*root)->prev = NULL;
		return (*root);
	}
	else if (!deleted->next)
	{
		tmp = deleted->prev;
		deleted->prev->next = NULL;
		return (tmp);
	}
	tmp = deleted->prev;
	deleted->next->prev = tmp;
	tmp->next = deleted->next;
	return (tmp);
}

void	delete_quotes(t_token **root)
{
	t_token	*tmp;

	tmp = *root;
	while (tmp)
	{
		if (tmp->type == 7 || tmp->type == 8)
			tmp = link_nodes(root, tmp);
		tmp = tmp->next;
	}
}
