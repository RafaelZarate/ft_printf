/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:23:37 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 05:09:10 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_args(char *fmt)
{
	size_t i;
	int	c;

	i = -1;
	c = 0;
	while (++i < ft_strlen(fmt) - 1)
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
			c++;
	}
	return (c);
}

void	handle_mfw(t_mst *args, int i, char **s)
{
	char *tmp;
	int len;

	tmp = *s;
	len = args->mfw[i] - (int)ft_strlen(tmp);
	if (len > 0)
	{
		char *s2;
		int i2;

		i2 = -1;
		s2 = ft_strnew(len);
		if (args->zero[i] == 1 && args->minus[i] == 0)
		{
			while (++i2 < len)
				s2[i2] = '0';
			*s = ft_strjoin(s2, tmp);
		}
		else
		{
			while (++i2 < len)
				s2[i2] = ' ';
			if (args->minus[i] == 1)
				*s = ft_strjoin(tmp, s2);
			else
				*s = ft_strjoin(s2, tmp);
		}
	}
}