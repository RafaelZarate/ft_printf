/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/17 17:27:04 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_mst	args;
	int		i;
	int		c_a;
	int		c;
	int		i2;
	t_uni	d_type;
	
	i = -1;
	c = 0;
	c_a = count_args((char *)fmt);
	i2 = 0;
	if (!fmt)
		return (-1);
	if (c_a == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	va_start(ap, fmt);
	arg_scanner((char *)fmt, &args, c_a);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			c++;
		}
		else if (fmt[i] == '%')
		{
			c += arg_handler(&args, ap, i2, &d_type);
			i += args.n_chars[i2];
			i2++;
		}
	}
	va_end(ap);
	struct_finalizer(&args);
	return (c);
}
