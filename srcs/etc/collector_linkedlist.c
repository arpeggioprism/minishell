/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:23:10 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/14 21:01:37 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_collector	*new_node_adr(void *adr, int key)
{
	t_collector	*node;

	node = malloc(sizeof(t_collector));
	if (!node)
		return (NULL);
	node->adr = adr;
	node->key = key;
	node->next = NULL;
	return (node);
}

t_collector	**append_adr(t_collector **root, void *adr, int key)
{
	t_collector	*node;
	t_collector	*tmp;

	tmp = *root;
	node = new_node_adr(adr, key);
	if (!*root)
		return (*root = node, root);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (root);
}

void	*ft_malloc(t_collector **root, size_t size, int key)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	else
		return (append_adr(root, ptr, key), ptr);
}

void	ft_collect(t_collector **root, t_collector *node, int key)
{
	if (!node)
		return ;
	ft_collect(root, node->next, key);
	if (key)
	{
		free(node->adr);
		node->adr = NULL;
		free(node);
		g_global.adrs = NULL;
		g_global.env = NULL;
	}
	else if (!key && node->key && node->adr)
	{
		free(node->adr);
		node->adr = NULL;
	}
}
