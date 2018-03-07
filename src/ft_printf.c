/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/07 08:05:29 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	count_args(char *fmt)
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

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_mst	args;
	int		i;
	int		c;
	int		i2;
	
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
			//c += arg_handler(&args, ap, i2);
			printf("ID: %i, FLAGS: %s, MFW: %i, PRE: %i, MOD: %i, ID: %c\n", i2, args.flags[i2], args.mfw[i2], args.precision[i2], args.mod[i2], args.id[i2]);
			i += args.n_chars[i2];
			i2++;
		}
	}
	va_end(ap);
	free(args.n_chars);
	free(args.id);
	free(args.flags);
	free(args.mod);
	free(args.precision);
	free(args.mfw);
	return (c);
}
