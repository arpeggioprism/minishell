/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_connecters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:19:13 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:08:51 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

int	take_less_more(char *str, t_token **root, const bool *comp)
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
	else if (comp)
		;
	return (0);
}

int	take_wp(char *str, t_token **root, const bool *comp)
{
	if (*str == '&' && *str != *(str + 1))
		return (invalid_token(root, str));
	if (*str != *(str + 1) || *str == '*')
		return (add_item(str, str + 1, check_flag(str, 1), root), 1);
	else if (*str == *(str + 1))
		return (add_item(str, str + 2, check_flag(str, 2), root), 2);
	else if (comp)
		;
	return (0);
}

int	take_par(char *str, t_token **root, const bool *comp)
{
	if (*str == '(')
		add_item(str, str + 1, OPAR, root);
	else
		add_item(str, str + 1, CPAR, root);
	if (comp)
		;
	return (1);
}
