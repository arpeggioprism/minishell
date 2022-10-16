/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:19:35 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/16 22:48:36 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	take_word(char *str, t_token **root)
{
	int		j;
	char	*comp;
	int		i;

	i = -1;
	comp = "&|\'\"$*<>~ \t\r\f\v\n()";
	while (str[++i])
	{
		j = -1;
		while (comp[++j])
			if (str[i] == comp[j])
				return (add_item(str, str + i, WORD, root), i);
	}
	return (add_item(str, str + i, WORD, root), i);
}

int	take_word2(char *str, t_token **root)
{
	int		j;
	char	*comp;
	int		i;

	i = -1;
	comp = "\'\"$";
	while (str[++i])
	{
		j = -1;
		while (comp[++j])
			if (str[i] == comp[j])
				return (add_item(str, str + i, WORD, root), i);
	}
	return (add_item(str, str + i, WORD, root), i);
}

int	take_space(char *str, t_token **root)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	add_item(str, str + i, WSPACE, root);
	return (i);
}

int	take_var(char *str, t_token **root)
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
