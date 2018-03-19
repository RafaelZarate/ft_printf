/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/18 20:16:17 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	printer(t_mst *args, va_list ap, char *fmt, t_uni *d_type)
{
	int i;
	int	i2;
	int c;

	c = 0;
	i2 = 0;
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			c++;
		}
		else if (fmt[i] == '%')
		{
			c += arg_handler(args, ap, i2, d_type);
			i += args->n_chars[i2];
			i2++;
		}
	}
	return (c);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_mst	args;
	int		c_a;
	int		c;
	t_uni	d_type;

	c = 0;
	c_a = count_args((char *)fmt);
	if (!fmt)
		return (-1);
	if (c_a == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	va_start(ap, fmt);
	arg_scanner((char *)fmt, &args, c_a);
	c = printer(&args, ap, (char *)fmt, &d_type);
	va_end(ap);
	struct_finalizer(&args);
	return (c);
}
