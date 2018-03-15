/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:33:39 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/14 20:20:32 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_i(t_mst *args, int i, t_uni *d_type)
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
	// // Needs some WORK, putnbr_li isn't working
	// else if (args->mod[i] == 2)
	// {
	// 	ft_putnbr_li(d_type->lint);
	// 	return (n_digits(d_type->lint));
	// }
	// else if (args->mod[i] == 4)
	// {
	// 	ft_putnbr(d_type->lint);
	// 	return (n_digits(d_type->lint));
	// }
	return (0);
}

int	handle_o(t_mst *args, int i, t_uni *d_type)
{
	char *s;

	if (args->mod[i] == 0)
		s = uitoa_base(d_type->i, 8);
	else if (args->mod[i] == 1)
		s = uitoa_base(d_type->uchar, 8);
	ft_putstr(s);
	return (ft_strlen(s));
}

int	handle_u(t_mst *args, int i, t_uni *d_type)
{
	char *s;

	if (args->mod[i] == 0)
		s = uitoa_base(d_type->i, 10);
	else if (args->mod[i] == 1)
		s = uitoa_base(d_type->uchar, 10);
	ft_putstr(s);
	return (ft_strlen(s));
}

int	handle_x(t_mst *args, int i, t_uni *d_type)
{
	char *s;


	if (args->id[i] == 'x')
	{
		if (args->mod[i] == 0)
			s = uitoa_base(d_type->i, 16);
		else if (args->mod[i] == 1)
			s = uitoa_base(d_type->uchar, 16);
	}
	else if (args->id[i] == 'X')
	{
		int x;

		x = -1;
		if (args->mod[i] == 0)
			s = uitoa_base(d_type->i, 16);
		else if (args->mod[i] == 1)
			s = uitoa_base(d_type->uchar, 16);
		while (++x < (int)ft_strlen(s))
			s[x] = ft_toupper(s[x]);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

int	handle_c(t_mst *args, int i, t_uni *d_type)
{
	if (args->mod[i] == 0 && args->id[i] == 'c')
		ft_putchar(d_type->c);
	if ((args->mod[i] == 0 && args->id[i] == 'C') || (args->mod[i] == 2 && args->id[i] == 'c'))
		ft_putchar_wc(d_type->wct);
	// AN ERROR SHOULD BE PROMPTED IF mod isn't 0
	return (1);
}

int	handle_s(t_mst *args, int i, t_uni *d_type)
{
	if (args->mod[i] == 0 && args->id[i] == 's')
	{
		ft_putstr(d_type->s);
        return (ft_strlen(d_type->s));
	}
	if ((args->mod[i] == 0 && args->id[i] == 'S') || (args->mod[i] == 2 && args->id[i] == 's'))
	{
		ft_putstr_wc(d_type->wcts);
        return (ft_strlen_wc(d_type->wcts));
	}
	return (1);
}

// int	handle_p(t_mst *args, int i, t_uni *d_type)
// {
// 	char *s;
// 	int n;

// 	n = &d_
// 	if (args->mod[i] == 0)
// 	{
// 		s = ft_strjoin("0x", uitoa_base(d_type->i, 16));
// 	}
// 	ft_putstr(s);
// 	return (ft_strlen(s));
// }
