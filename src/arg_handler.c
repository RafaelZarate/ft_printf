/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 06:54:01 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	arg_handler(t_mst *args, va_list ap, int i)
{
	if (args->id[i] == 's')
	{
		char *s;
		
		s = va_arg(ap, char *);
		ft_putstr(s);
		return (ft_strlen(s));
	}
	// if (args->id[i] == 'S')
	// {
	// 	wchar_t *s;
		
	// 	s = va_arg(ap, wchar_t *);
	// 	ft_putstr(s);
	// 	return (ft_strlen(s));
	// }
	else if (args->id[i] == 'i')
	{
		int n;

		n = va_arg(ap, int);
		ft_putnbr(n);
		return (n_digits(n));
	}
	else if (args->id[i] == 'c')
	{
		unsigned char c;

		c = (unsigned char)va_arg(ap, int);
		write(1, &c, 1);
		return (1);
	}
	return (0);
}