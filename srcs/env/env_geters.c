/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_geters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:03:05 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:26 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*get_env_node(char *str)
{
	t_env	*tmp;

	tmp = g_global.env;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_env_value(char *str)
{
	t_env	*tmp;

	tmp = g_global.env;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	delete_env(t_env **root, t_env *deleted)
{
	t_env	*last;
	t_env	*deletedprev;

	if (!deleted)
		return ;
	if (deleted == *root)
		*root = deleted->next;
	else if (!deleted->next)
	{
		last = *root;
		while (last->next->next)
			last = last->next;
		last->next = NULL;
	}
	else
	{
		deletedprev = *root;
		while (deletedprev->next != deleted)
			deletedprev = deletedprev->next;
		deletedprev->next = deleted->next;
	}
}

int	envlstsize(t_env *root)
{
	int	i;

	i = 0;
	while (root)
	{
		i++;
		root = root->next;
	}
	return (i);
}
