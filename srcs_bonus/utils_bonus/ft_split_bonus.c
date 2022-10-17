/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:34:16 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:25:05 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

int	ft_is_separator(char c, char cr)
{
	if (c == cr)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_words(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (ft_is_separator(str[i], c) == 0
			&& ft_is_separator(str[i + 1], c) == 1)
			w++;
		i++;
	}
	return (w);
}

void	ft_write_word(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (ft_is_separator(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_write_split(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (ft_is_separator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_separator(str[i + j], c) == 0)
				j++;
			split[w] = (char *)ft_malloc(g_global.cur, \
			sizeof(char) * (j + 1), 1);
			if (!(split + w))
				return (0);
			ft_write_word(split[w], str + i, c);
			i += j;
			w++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**rtn;

	if (!s || !*s)
		return (NULL);
	w = ft_words((char *)s, c);
	rtn = (char **)ft_malloc(g_global.cur, sizeof(char *) * (w + 1), 1);
	if (!rtn)
		return (NULL);
	if (!(ft_write_split(rtn, (char *) s, c)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
