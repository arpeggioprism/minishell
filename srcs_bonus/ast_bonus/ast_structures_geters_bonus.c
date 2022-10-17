/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_structures_geters_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:06 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:10:26 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

t_tree	*get_wp(int type, t_tree *left, t_tree *right)
{
	t_wp	*node;

	node = ft_malloc(g_global.cur, sizeof(t_wp), 1);
	node->type = type;
	node->left = left;
	node->right = right;
	return ((t_tree *)node);
}

t_tree	*get_cmdnode(t_cmd *next)
{
	t_cmd	*node;

	(void)next;
	node = ft_malloc(g_global.cur, sizeof(t_cmd), 1);
	node->type = CMD;
	node->next = NULL;
	return ((t_tree *)node);
}

t_tree	*get_sub(t_tree *next)
{
	t_sub	*node;

	node = ft_malloc(g_global.cur, sizeof(t_sub), 1);
	node->type = SUB;
	node->next = next;
	return ((t_tree *)node);
}

int	get_type(t_token *head)
{
	if (head->type == PIPE)
		return (T_PIPE);
	if (head->type == AND)
		return (T_AND);
	if (head->type == OR)
		return (T_OR);
	return (-1);
}

t_command	*get_nodelist(char *content)
{
	t_command	*node;

	node = ft_malloc(g_global.cur, sizeof(t_command), 1);
	node->type = CMD;
	node->next = NULL;
	node->content = content;
	return (node);
}
