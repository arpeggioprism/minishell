/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes_in_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:19:23 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:35 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	take_dquote2(char *str, t_token **root)
{
	int	i;

	i = 0;
	add_item(str, str + 1, DQUOTE, root);
	str++;
	while (str[i] != '\"' && str[i])
		i += check_char2(str, root);
	if (str[i] == '\"')
		add_item(str + i, str + i + 1, DQUOTE, root);
	else if (!str[i])
		return (unclosed_quote(root), (i + 1));
	return (i + 2);
}

int	take_colon2(char *str, t_token **root)
{
	int	i;

	i = 0;
	if (*str == '\"')
		return (take_dquote2(str, root));
	while (str[i] != '\"' && str[i])
		i++;
	if (str[i] == '\"')
		add_item(str, str + i, WORD, root);
	return (i);
}
