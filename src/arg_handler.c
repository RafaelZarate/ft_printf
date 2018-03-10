/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/10 07:08:48 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	arg_handler(t_mst *args, va_list ap, int i, t_uni *d_type)
{
	if (args->mod[i] == 1 && args->id[i] == 'i')
		d_type->schar = va_arg(ap, int);
	else if (args->mod[i] == 1 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
		d_type->uchar = va_arg(ap, unsigned int);
	else if (args->mod[i] == 2 && args->id[i] == 'i')
		d_type->lint = va_arg(ap, long);
	else if (args->mod[i] == 2 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
		d_type->ulint = va_arg(ap, unsigned long);
	else if (args->mod[i] == 3 && args->id[i] == 'i')
		d_type->llint = va_arg(ap, long long);
	else if (args->mod[i] == 3 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
		d_type->ullint = va_arg(ap, unsigned long long);
	else if (args->mod[i] == 4 &&args->id[i] == 'i')
		d_type->imt = va_arg(ap, intmax_t);
	else if (args->mod[i] == 4 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
		d_type->uimt = va_arg(ap, uintmax_t);
	else if (args->mod[i] == 5 && args->id[i] == 'i')
		d_type->sst = va_arg(ap, ssize_t);
	else if (args->mod[i] == 5 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
		d_type->st = va_arg(ap, size_t);
	else if (args->mod[i] == 0 && ((args->id[i] == 'i') || (args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X') || (args->id[i] == 'c')))
		d_type->i = va_arg(ap, int);
	else if (args->mod[i] == 0 && args->id[i] == 's')
		d_type->s = va_arg(ap, char *);
	else if (args->mod[i] == 0 && args->id[i] == 'S')
		d_type->wcts = va_arg(ap, wchar_t *);
	else if (args->mod[i] == 0 && args->id[i] == 'p')
		d_type->p = va_arg(ap, void *);
	else if (args->mod[i] == 0 && ((args->id[i] == 'D') || (args->id[i] == 'O') || (args->id[i] == 'U')))
		d_type->lint = va_arg(ap, long);
    else if (args->id[i] == 'C')
        d_type->wct = va_arg(ap, wchar_t);
    else if (args->mod[i] == 0 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
        d_type->uimt = va_arg(ap, uintmax_t);

    // printing and returning n of chars printed
    if (args->mod[i] == 0 && args->id[i] == 'c')
    {
		ft_putchar(d_type->c);
        return (1);
    }
    else if ((args->id[i] == 'C') || (args->mod[i] == 2 && args->id[i] == 'c'))
    {
        ft_putchar_wc(d_type->wct);
        return (1);
    }
    else if (args->mod[i] == 0 && args->id[i] == 's')
    {
		ft_putstr(d_type->s);
        return (ft_strlen(d_type->s));
    }
    else if ((args->id[i] == 'S') || (args->mod[i] == 2 && args->id[i] == 's'))
    {
        ft_putstr_wc(d_type->wcts);
        return (ft_strlen_wc(d_type->wcts));
    }
    else if (args->id[i] == 'i')
    {
		if (args->mod[i] == 0)
		{
			ft_putnbr(d_type->i);
			return (n_digits(d_type->i));
		}
		else if (args->mod[i] == 1)
		{
			ft_putnbr(d_type->schar);
			return (n_digits(d_type->schar));
		}
		// Needs some WORK, putnbr_li isn't working
		else if (args->mod[i] == 2)
		{
			ft_putnbr_li(d_type->lint);
			return (n_digits(d_type->lint));
		}
		else if (args->mod[i] == 4)
		{
			ft_putnbr(d_type->lint);
			return (n_digits(d_type->lint));
		}
    }
    else if (args->mod[i] == 0 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
	{
		char *s;

		if (args->id[i] == 'o')
			s = uitoa_base(d_type->uimt, 8);
		else if (args->id[i] == 'u')
			s = uitoa_base(d_type->uimt, 10);
		else if (args->id[i] == 'x')
			s = uitoa_base(d_type->uimt, 16);
		else if (args->id[i] == 'X')
		{
			int i;

			i = -1;
			s = uitoa_base(d_type->uimt, 16);
			while (++i < (int)ft_strlen(s))
				s[i] = ft_toupper(s[i]);
		}
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else if (args->mod[i] == 1 && ((args->id[i] == 'o') || (args->id[i] == 'u') || (args->id[i] == 'x') || (args->id[i] == 'X')))
	{
		char *s;

		if (args->id[i] == 'o')
			s = uitoa_base(d_type->uchar, 8);
		else if (args->id[i] == 'u')
			s = uitoa_base(d_type->uchar, 10);
		else if (args->id[i] == 'x')
			s = uitoa_base(d_type->uchar, 16);
		else if (args->id[i] == 'X')
		{
			int i;

			i = -1;
			s = uitoa_base(d_type->uchar, 16);
			while (++i < (int)ft_strlen(s))
				s[i] = ft_toupper(s[i]);
		}
		ft_putstr(s);
		return (ft_strlen(s));
	}
	
    // else if ((args->id[i] == 'I') || (args->mod[i] == 2 && args->id[i] == 'i'))
    // {
    //     ft_putnbr_li(d_type->lint);
    //     return (n_digits(d_type->lint));
    // }
    // else if ((args->id[i] == 'D'))
    // {
    //     ft_putnbr_li(d_type->lint);
    //     return (n_digits(d_type->lint));
    // }
	return (0);
}

// int	arg_handler(t_mst *args, va_list ap, int i, t_uni *d_tpye)
// {
// 	d_type->i = 10;
// 	if (args->id[i] == 's')
// 	{
// 		char *s;
		
// 		s = va_arg(ap, char *);
// 		ft_putstr(s);
// 		return (ft_strlen(s));
// 	}
// 	if (args->id[i] == 'S')
// 	{
// 		wchar_t *s;
		
// 		s = va_arg(ap, wchar_t *);
// 		ft_putstr_wc(s);
// 		return (ft_strlen_wc(s));
// 	}
// 	else if (args->id[i] == 'i')
// 	{
// 		int n;

// 		n = va_arg(ap, int);
// 		ft_putnbr(n);
// 		return (n_digits(n));
// 	}
// 	else if (args->id[i] == 'c')
// 	{
// 		unsigned char c;

// 		c = (unsigned char)va_arg(ap, int);
// 		write(1, &c, 1);
// 		return (1);
// 	}
	// else if (args->id[i] == 'o')
	// {
	// 	unsigned int n;
	// 	char *s;

	// 	n = va_arg(ap, unsigned int);
	// 	s = uitoa_base(n, 8);
	// 	ft_putstr(s);
	// 	return (ft_strlen(s));
	// }
	// else if (args->id[i] == 'u')
	// {
	// 	unsigned int n;

	// 	n = va_arg(ap, unsigned int);
	// 	ft_putnbr_ui(n);
	// 	return (6);
	// }
	// else if (args->id[i] == 'x')
	// {
	// 	unsigned int n;
	// 	char *s;

	// 	n = va_arg(ap, unsigned int);
	// 	s = uitoa_base(n, 16);
	// 	ft_putstr(s);
	// 	return (ft_strlen(s));
	// }
	// else if (args->id[i] == 'X')
	// {
	// 	unsigned int n;
	// 	char *s;
	// 	int i;

	// 	i = -1;
	// 	n = va_arg(ap, unsigned int);
	// 	s = uitoa_base(n, 16);
	// 	while (++i < (int)ft_strlen(s))
	// 		s[i] = ft_toupper(s[i]);
	// 	ft_putstr(s);
	// 	return (ft_strlen(s));
	// }
// 	return (0);
// }