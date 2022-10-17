/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:20:07 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:08:41 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	unclosed_quote(t_token **root)
{
	ft_putstr_fd("unclosed quote\n", 1);
	*root = NULL;
}

int	invalid_token(t_token **root, char *str)
{
	*root = NULL;
	ft_putstr_fd("unexpected token\n", 1);
	return (get_last(str));
}

int	get_last(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	calc_size(char *start, char *end)
{
	int	i;

	i = 1;
	while (start++ != end)
		i++;
	return (i);
}

int	check_flag(char *str, int q)
{
	if (*str == '|')
	{
		if (q == 1)
			return (PIPE);
		else
			return (OR);
	}
	else if (*str == '&')
		return (AND);
	else if (*str == '*')
		return (WILD);
	return (0);
}
