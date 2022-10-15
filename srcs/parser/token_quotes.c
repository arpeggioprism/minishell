/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:19:23 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 02:26:55 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	take_dquote(char *str, t_token **root)
{
	int	i;
	char except[2] = "";

	i = 0;
	add_item(str, str + 1, DQUOTE, root);
	str++;
	while (str[i] != '\"' && str[i])
		i += check_char2(str + i, root);
	if (str[i] == '\"')
	{
		if (i == 0)
			add_item(except, &except[0] + 1, WORD, root);
		add_item(str + i, str + i + 1, DQUOTE, root);
	}
	else if (!str[i])
	{
		return (unclosed_quote(root), (i + 1));
	}
	return (i + 2);
}

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

int	check_closed_dq(t_token **root, char *str, int i, int last)
{
	if (str [i] == '\"' && last == 0)
	{
		add_item(str, str + i, WORD, root);
		add_item(str + i, str + i + 1, DQUOTE, root);
	}
	else if (str [i] == '\"' && last != 0)
	{
		add_item(str + last + 1, str + i, WORD, root);
		add_item(str + i, str + i + 1, DQUOTE, root);
	}
	else if (!str[i])
		return (unclosed_quote(root), i + 1);
	return (i + 2);
}

int	take_qvar(char *str, t_token **root)
{
	char	*comp;
	int		i;
	int		j;

	i = 0;
	comp = "!@#$*+-~./, \t\r\f\v\n\"()";
	while (str[++i])
	{
		j = -1;
		while (comp[++j])
			if (str[i] == comp[j])
				return (add_item(str, str + i, VAR, root), i);
	}
	return (i);
}

int	take_colon(char *str, t_token **root)
{
	int	i;

	i = 0;
	if (*str == '\"')
		return (take_dquote(str, root));
	add_item(str, str + 1, SQUOTE, root);
	str++;
	while (str[i] != '\'' && str[i])
		i++;
	if (str[i] == '\'')
	{
		add_item(str, str + i, WORD, root);
		add_item(str + i, str + i + 1, SQUOTE, root);
	}
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

void	*add_item(char *start, char *end, int flag, t_token **root)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)ft_malloc(g_global.cur, calc_size(start, end), 1);
	if (!str)
		return (NULL);
	while (start != end)
		str[++i] = *(start++);
	str[++i] = 0;
	append_in_end(root, str, flag);
	return (NULL);
}
