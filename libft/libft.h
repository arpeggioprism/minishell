/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:26:38 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 02:16:33 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isdigit(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
