/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:31 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:22 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*get_full(t_token **head)
{
	t_tree	*ret;
	t_token	*tmp;

	tmp = *head;
	if (tmp == *head && tmp->type != 6)
		;
	else
		tmp = get_right(tmp);
	ret = get_block(&tmp);
	return ((t_tree *)ret);
}
