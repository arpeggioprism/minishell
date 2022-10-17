/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_linkedlist_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:18:37 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:09:03 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

t_token	*new_node(char *str, int flag)
{
	t_token	*new;

	new = (t_token *)ft_malloc(g_global.cur, sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new->str = str;
	new->type = flag;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	append_in_end(t_token **root, char *str, int flag)
{
	t_token	*tmp;
	t_token	*p;

	tmp = new_node(str, flag);
	if (!*root)
		*root = tmp;
	else
	{
		p = *root;
		while (p->next)
			p = p->next;
		p->next = tmp;
		tmp->prev = p;
	}
}

void	display_node(t_token *root)
{
	t_token	*temp;

	temp = root;
	if (!root)
		return ;
	else
	{
		temp = root;
		while (temp)
		{
			printf("[%d]=>[%s]\n", temp->type, temp->str);
			temp = temp->next;
		}
	}
}

void	clr_lst(t_token **root, t_token *node)
{
	if (node == NULL)
		return ;
	clr_lst(root, node->next);
	free(node);
}
