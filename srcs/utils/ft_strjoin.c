/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:35:44 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/15 15:39:52 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst > src)
	{
		while (len--)
			*(char *)(dst + len) = *(char *)(src + len);
	}
	else if (src > dst)
	{
		while (++i < len)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	ptr = (char *)ft_malloc(g_global.cur, (i1 + i2) * sizeof(char) + 1, 1);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, i1);
	ft_memmove(ptr + i1, s2, i2 + 1);
	ptr[i1 + i2] = 0;
	return (ptr);
}
