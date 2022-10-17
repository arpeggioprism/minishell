/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:37:54 by jshin             #+#    #+#             */
/*   Updated: 2022/10/17 10:09:53 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	set_fp_n_comp(int (**fp)(char *, t_token **, const bool *), \
bool *comp, unsigned int i)
{
	while (i < 9)
		fp[i++] = take_word;
	while (i < 14)
		fp[i++] = take_space;
	while (i < 32)
		fp[i++] = take_word;
	fp[i++] = take_space;
	fp[i++] = take_word;
	fp[i++] = take_colon;
	fp[i++] = take_word;
	fp[i++] = take_var;
	fp[i++] = take_word;
	fp[i++] = take_wp;
	fp[i++] = take_colon;
	fp[i++] = take_par;
	fp[i++] = take_par;
	fp[i++] = take_wp;
	while (i < 60)
		fp[i++] = take_word;
	fp[i++] = take_less_more;
	fp[i++] = take_word;
	fp[i++] = take_less_more;
	set_fp_n_comp2(fp, comp, i);
}

void	set_fp_n_comp2(int (**fp)(char *, t_token **, const bool *), \
bool *comp, unsigned int i)
{
	while (i < 124)
		fp[i++] = take_word;
	fp[i++] = take_wp;
	fp[i++] = take_word;
	fp[i++] = add_item_int;
	while (i < 256)
		fp[i++] = take_word;
	ft_memset(comp, 0, 256);
	comp[')'] = ((comp['&'] = 1, comp['|'] = 1, comp['\''] = 1, comp['\"'] = 1, \
	comp['$'] = 1, comp['*'] = 1, comp['<'] = 1, comp['>'] = 1, \
	comp['~'] = 1, comp[' '] = 1, comp['\t'] = 1, comp['\r'] = 1, \
	comp['\f'] = 1, comp['\v'] = 1, comp['\n'] = 1, comp['('] = 1, 1));
}
