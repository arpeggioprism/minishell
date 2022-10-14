/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:33:58 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/14 21:04:33 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_nbr(long long n, int len, char *r)
{

	while (n)
	{
		r[len--] = 48 + (n % 10);
		n /= 10;
	}
}

int	ft_len(int n)
{
	int	c;

	c = 0;
	if (n < 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			len;
	char		*r;

	len = ft_len(n);
	if (!len)
	{
		r = (char *)ft_malloc(&g_global.adrs, sizeof(char) * 2, 1);
		if (!r)
			return (NULL);
		r[1] = (r[0] = '0', 0);
		return (r);
	}
	r = (char *)ft_malloc(&g_global.adrs, len * sizeof(char) + 1, 1);
	if (!r)
		return (NULL);
	r[len--] = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		r[0] = '-';
	}
	ft_nbr(nb, len, r);
	return (r);
}
