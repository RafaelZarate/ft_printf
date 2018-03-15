/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 04:31:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/10 04:35:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_ldigits(long n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		r++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		r++;
		n /= 10;
	}
	return (r);
}

char			*ft_litoa(long n)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = n_digits(n);
	// if (n == -9223372036854775808)
	// 	return (ft_strdup("-9223372036854775808"));
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		i = 1;
		s[0] = '-';
	}
	while (--len >= i)
	{
		s[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
