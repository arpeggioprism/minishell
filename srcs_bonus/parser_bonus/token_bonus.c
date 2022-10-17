/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:20:14 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:09:01 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

t_tree	*token(int (**fp)(char *, t_token **, const bool *), char *str, \
t_token **root, const bool *comp)
{
	int		i;
	t_tree	*head;

	i = 0;
	head = NULL;
	while (str[i])
		i += fp[(int)str[i]](str + i, root, comp);
	if (*root)
	{
		if (!check_syntax(root))
			return (NULL);
		delete_quotes(root);
		head = get_full(root);
	}
	return (head);
}

int	check_char2(char *str, t_token **root)
{
	if (*str == ')' || *str == '(')
		return (take_par2(str, root));
	else if (*str == '$')
		return (take_var2(str, root));
	else if (*str == '\'' || *str == '\"')
		return (take_colon2(str, root));
	else
		return (take_word2(str, root));
	return (0);
}
