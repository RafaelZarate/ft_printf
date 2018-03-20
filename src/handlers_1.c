/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:33:39 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/20 11:59:37 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_i(t_mst *args, int i, t_uni *d_type)
{
	char	*s;

	if (args->mod[i] == 2 || (args->id[i] == 'D'))
		s = ft_itoa(d_type->lint);
	else if (args->mod[i] == 0)
		s = ft_itoa(d_type->i);
	else if (args->mod[i] == 1)
		s = ft_itoa(d_type->schar);
	else if (args->mod[i] == 3)
		s = ft_itoa(d_type->llint);
	else if (args->mod[i] == 4)
		s = ft_itoa(d_type->imt);
	else if (args->mod[i] == 5)
		s = ft_itoa(d_type->si);
	else if (args->mod[i] == 6)
		s = ft_itoa(d_type->sst);
	i_helper(args, i, &s);
	return (p_and_f(&s));
}

int	handle_o(t_mst *args, int i, t_uni *d_type)
{
	char	*s;

	if (args->mod[i] == 0)
		s = uitoa_base(d_type->ui, 8);
	else if (args->mod[i] == 1)
		s = uitoa_base(d_type->uchar, 8);
	else if (args->mod[i] == 2)
		s = uitoa_base(d_type->ulint, 8);
	else if (args->mod[i] == 3)
		s = uitoa_base(d_type->ullint, 8);
	else if (args->mod[i] == 4)
		s = uitoa_base(d_type->uimt, 8);
	else if (args->mod[i] == 5)
		s = uitoa_base(d_type->st, 8);
	else if (args->mod[i] == 6)
		s = uitoa_base(d_type->usi, 8);
	if (args->hash[i] == 1 && s[0] != '0')
		s = ft_strjoin("0", s);
	handle_mfw(args, i, &s);
	return (p_and_f(&s));
}

int	handle_u(t_mst *args, int i, t_uni *d_type)
{
	char	*s;
	int		n;

	if (args->mod[i] == 0)
		s = uitoa_base(d_type->ui, 10);
	else if (args->mod[i] == 1)
		s = uitoa_base(d_type->uchar, 10);
	else if (args->mod[i] == 2)
		s = uitoa_base(d_type->ulint, 10);
	else if (args->mod[i] == 3)
		s = uitoa_base(d_type->ullint, 10);
	else if (args->mod[i] == 4)
		s = uitoa_base(d_type->uimt, 10);
	else if (args->mod[i] == 5)
		s = uitoa_base(d_type->st, 10);
	else if (args->mod[i] == 6)
		s = uitoa_base(d_type->usi, 10);
	handle_mfw(args, i, &s);
	return (p_and_f(&s));
}

int	handle_x(t_mst *args, int i, t_uni *d_type)
{
	char	*s;
	int		n;

	if (args->mod[i] == 0)
		s = uitoa_base(d_type->ui, 16);
	else if (args->mod[i] == 1)
		s = uitoa_base(d_type->uchar, 16);
	else if (args->mod[i] == 2)
		s = uitoa_base(d_type->ulint, 16);
	else if (args->mod[i] == 3)
		s = uitoa_base(d_type->ullint, 16);
	else if (args->mod[i] == 4)
		s = uitoa_base(d_type->uimt, 16);
	else if (args->mod[i] == 5)
		s = uitoa_base(d_type->st, 16);
	else if (args->mod[i] == 6)
		s = uitoa_base(d_type->usi, 16);
	if (args->hash[i] == 1)
		s = ft_strjoin("0x", s);
	(args->id[i] == 'X') ? ft_strtoupper(&s) : 0;
	handle_mfw(args, i, &s);
	return (p_and_f(&s));
}

int	handle_c(t_mst *args, int i, t_uni *d_type)
{
	char	*s;
	int		n;

	if (args->mfw[i] == 0)
	{
		ft_putchar(d_type->c);
		return (1);
	}
	s = ft_strnew(1);
	if (args->mod[i] == 0 && args->id[i] == 'c')
		s[0] = d_type->c;
	if ((args->mod[i] == 0 && args->id[i] == 'C') ||
			(args->mod[i] == 2 && args->id[i] == 'c'))
		s[0] = (char)d_type->wct;
	handle_mfw(args, i, &s);
	return (p_and_f(&s));
}
