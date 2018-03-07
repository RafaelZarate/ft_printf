/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 23:30:04 by rzarate          ###   ########.fr       */
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
	else if (args->id[i] == 'o')
	{
		unsigned int n;
		char *s;

		n = va_arg(ap, unsigned int);
		s = uitoa_base(n, 8);
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else if (args->id[i] == 'u')
	{
		unsigned int n;

		n = va_arg(ap, unsigned int);
		ft_putnbr_ui(n);
		return (6);
	}
	else if (args->id[i] == 'x')
	{
		unsigned int n;
		char *s;

		n = va_arg(ap, unsigned int);
		s = uitoa_base(n, 16);
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else if (args->id[i] == 'X')
	{
		unsigned int n;
		char *s;
		int i;

		i = -1;
		n = va_arg(ap, unsigned int);
		s = uitoa_base(n, 16);
		while (++i < (int)ft_strlen(s))
			s[i] = ft_toupper(s[i]);
		ft_putstr(s);
		return (ft_strlen(s));
	}
	return (0);
}