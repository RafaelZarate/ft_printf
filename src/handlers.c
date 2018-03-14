/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:33:39 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/14 13:14:46 by rzarate          ###   ########.fr       */
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
		int i;

		i = -1;
		if (args->mod[i] == 0)
			s = uitoa_base(d_type->i, 16);
		else if (args->mod[i] == 1)
			s = uitoa_base(d_type->uchar, 16);
		while (++i < (int)ft_strlen(s))
			s[i] = ft_toupper(s[i]);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}