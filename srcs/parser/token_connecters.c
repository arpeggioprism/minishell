/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_connecters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:19:13 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/14 21:02:44 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	take_less_more(char *str, t_token **root)
{
	if (*str == '<')
	{
		if (*(str + 1) == '<')
			return (add_item(str, str + 2, DLESS, root), 2);
		else
			return (add_item(str, str + 1, LESS, root), 1);
	}
	if (*str == '>')
	{
		if (*(str + 1) == '>')
			return (add_item(str, str + 2, DGREAT, root), 2);
		else
			return (add_item(str, str + 1, GREAT, root), 1);
	}
	return (0);
}

int	take_wp(char *str, t_token **root)
{
	if (*str == '&' && *str != *(str + 1))
		return (invalid_token(root, str));
	if (*str != *(str + 1) || *str == '*')
		return (add_item(str, str + 1, check_flag(str, 1), root), 1);
	else if (*str == *(str + 1))
		return (add_item(str, str + 2, check_flag(str, 2), root), 2);
	return (0);
}

int	take_par(char *str, t_token **root)
{
	if (*str == '(')
		add_item(str, str + 1, OPAR, root);
	else
		add_item(str, str + 1, CPAR, root);
	return (1);
}
