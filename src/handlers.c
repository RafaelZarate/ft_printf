/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:33:39 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/17 19:22:59 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_i(t_mst *args, int i, t_uni *d_type)
{
	char *s;
	int		neg;
	int		len;

	if (args->mod[i] == 0)
		s = ft_itoa(d_type->i);
	else if (args->mod[i] == 1)
		s = ft_itoa(d_type->schar);
	else if (args->mod[i] == 2 || (args->id[i] == 'D'))
		s = ft_itoa(d_type->lint);
	else if (args->mod[i] == 3)
		s = ft_itoa(d_type->llint);
	else if (args->mod[i] == 4)
		s = ft_itoa(d_type->imt);
	else if (args->mod[i] == 5)
		s = ft_itoa(d_type->si);
	else if (args->mod[i] == 6)
		s = ft_itoa(d_type->sst);
	else
		return (0);
	neg = (s[0] == '-') ? 1 : 0;
	len = args->mfw[i] - (int)ft_strlen(s);
	handle_mfw_i(args, i, &s, neg);

	/*POSSIBLE FLAGS*/
	if (args->plus[i] == 1 && neg == 0)
		handle_plus_i(args, &s, len);
	else if (args->space[i] == 1 && d_type->imt >= 0)
	{
		if (args->mfw[i] == 0)
			s = ft_strjoin(" ", s);
		else
			s[0] = ' ';
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

int	handle_o(t_mst *args, int i, t_uni *d_type)
{
	char *s;

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
	
	/*POSSIBLE FLAGS*/
	if (args->hash[i] == 1 && s[0] != '0')
			s = ft_strjoin("0", s);
	handle_mfw(args, i, &s);
	ft_putstr(s);
	return (ft_strlen(s));
}

int	handle_u(t_mst *args, int i, t_uni *d_type)
{
	char *s;
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
	ft_putstr(s);
	n = ft_strlen(s);
	free(s);
	return (n);
}

int	handle_x(t_mst *args, int i, t_uni *d_type)
{
	char *s;
	int n;

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

	/*POSSIBLE FLAGS*/
	if (args->hash[i] == 1)
			s = ft_strjoin("0x", s);
	
	if (args->id[i] == 'X')
		ft_strtoupper(&s);
	
	handle_mfw(args, i, &s);
	ft_putstr(s);
	n = ft_strlen(s);
	free(s);
	return (n);
}

int	handle_c(t_mst *args, int i, t_uni *d_type)
{
	char	*s;
	int		n;
	
	s = ft_strnew(1);
	if (args->mod[i] == 0 && args->id[i] == 'c')
		s[0] = d_type->c;
	if ((args->mod[i] == 0 && args->id[i] == 'C') || (args->mod[i] == 2 && args->id[i] == 'c'))
		s[0] = (char)d_type->wct;

	handle_mfw(args, i, &s);
	ft_putstr(s);
	n = ft_strlen(s);
	free(s);
	return (n);
}

int	handle_s(t_mst *args, int i, t_uni *d_type)
{
	char	*s;
	int		n;
	
	if (args->mod[i] == 0 && args->id[i] == 's')
		s = d_type->s;
	if ((args->mod[i] == 0 && args->id[i] == 'S') || (args->mod[i] == 2 && args->id[i] == 's'))
		s = (char *)d_type->wcts;

	handle_mfw(args, i, &s);
	ft_putstr(s);
	n = ft_strlen(s);
	return (n);
}

int	handle_p(t_mst *args, int i, t_uni *d_type)
{
	char *s;

	s = ft_strjoin("0x", uitoa_base(d_type->uimt, 16));
	ft_putstr(s);
	return (ft_strlen(s));
}

int	handle_per(t_mst *args, int i)
{
	char	*s;
	int		n;
	
	s = ft_strnew(1);
	s[0] = '%';

	handle_mfw(args, i, &s);
	ft_putstr(s);
	n = ft_strlen(s);
	free(s);
	return (n);
}
