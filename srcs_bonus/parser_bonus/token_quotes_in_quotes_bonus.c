/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes_in_quotes_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:19:23 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:08:46 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

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

int	take_var2(char *str, t_token **root)
{
	char	*comp;
	int		i;
	int		j;

	i = 0;
	if (str[1] == '\"')
	{
		add_item(str, str + 1, WORD, root);
		return (1);
	}
	if (!ft_strncmp(str, "$$", 2))
		return (add_item(str, str + 2, VAR, root), 2);
	if (*str == '$' && (*(str + 1) == ' ' || *(str + 1) == 0))
		return (add_item(str, str + 1, WORD, root), 1);
	comp = "&|\'\"$*<>~ \t\r\f\v\n()";
	while (str[++i])
	{
		j = -1;
		while (comp[++j])
			if (str[i] == comp[j])
				return (add_item(str, str + i, VAR, root), i);
	}
	return (add_item(str, str + i, VAR, root), i);
}

int	take_par2(char *str, t_token **root)
{
	if (*str == '(')
		add_item(str, str + 1, OPAR, root);
	else
		add_item(str, str + 1, CPAR, root);
	return (1);
}
