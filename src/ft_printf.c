/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 04:07:47 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_mst	args;
	int		i;
	int		c;
	int		i2;
	t_uni	d_type;
	
	i = -1;
	c = 0;
	i2 = 0;
	if (!fmt)
		return (-1);
	if (count_args((char *)fmt) == 0)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	va_start(ap, fmt);
	arg_scanner((char *)fmt, &args, count_args((char *)fmt));
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			c++;
		}
		else if (fmt[i] == '%' && fmt[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
			c++;
		}
		else
		{
			c += arg_handler(&args, ap, i2, &d_type);
			i += args.n_chars[i2];
			i2++;
		}
	}
	va_end(ap);
	free(args.n_chars);
	free(args.id);
	i = -1;
	free(args.hash);
	free(args.zero);
	free(args.minus);
	free(args.plus);
	free(args.space);
	free(args.mod);
	free(args.precision);
	free(args.mfw);
	return (c);
}
