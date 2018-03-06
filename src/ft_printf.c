/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 02:21:07 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	count_args(char *input)
{
	size_t i;
	int	c;

	i = -1;
	c = 0;
	while (++i < ft_strlen(input) - 1)
	{
		if (input[i] == '%' && input[i + 1] != '%')
			c++;
	}
	return (c);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n_args;
	t_list	a_list;
	int		i;
	int		c;
	
	i = -1;
	if (!fmt)
		return (-1);
	n_args = count_args((char *)fmt);
	if (n_args == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	va_start(ap, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			c++;
		}
		else
			c += arg_hander(fmt, i, ap);
	}
	va_end(ap);
	return (0);
}
