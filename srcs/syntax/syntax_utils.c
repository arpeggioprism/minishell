/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:21:15 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/15 16:02:37 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_begin(t_token *root)
{
	if (root->type >= VAR && root->type <= 11)
		return (1);
	else
		return (0);
}

t_token	*get_right(t_token *root)
{
	if (root->next && root->next->type == 6)
	{
		if (root->next->next)
			return (root->next->next);
		else
			return (NULL);
	}
	else
		return (root->next);
}

t_token	*get_left(t_token *root)
{
	if (root->prev && root->prev->type == 6)
	{
		if (root->prev->prev)
			return (root->prev->prev);
		else
			return (NULL);
	}
	else
		return (root->prev);
}

void	syntax_error(void)
{
	ft_putstr_fd("syntax Error\n", 1);
}

int	check_bal_par(t_token **root)
{
	int		l;
	t_token	*temp;

	if (!*root)
		return (0);
	l = 0;
	temp = *root;
	while (temp)
	{
		if (temp->type == 9)
			l++;
		else if (temp->type == 15)
			l-- ;
		if (l < 0)
			return ((void)(syntax_error()), 0);
		temp = temp->next;
	}
	if (l)
		return (syntax_error(), 0);
	return (1);
}
