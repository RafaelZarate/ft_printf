/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_scanner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:18:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 04:23:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_scanner(char *fmt, t_mst *args, int n)
{
	size_t	i;
	int	x;
	int i2;

	i = -1;
	i2 = 0;
	args->hash = (int *)ft_memalloc(sizeof(int) * n);
	args->zero = (int *)ft_memalloc(sizeof(int) * n);
	args->minus = (int *)ft_memalloc(sizeof(int) * n);
	args->plus = (int *)ft_memalloc(sizeof(int) * n);
	args->space = (int *)ft_memalloc(sizeof(int) * n);
	args->mfw = (int *)ft_memalloc(sizeof(int) * n);
	args->precision = (int *)ft_memalloc(sizeof(int) * n);
	args->mod = (int *)ft_memalloc(sizeof(int) *n);
	args->id = ft_strnew(n);
	args->n_chars = (int *)ft_memalloc(sizeof(int) *n);
	while (++i < ft_strlen(fmt) - 1)
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			x = i + 1;
			x += check_flags(fmt, x, args, i2);
			x += check_mfw(fmt, x, args, i2);
			x += check_precision(fmt, x, args, i2);
			x += check_mod(fmt, x, args, i2);
			args->id[i2] = check_ids(fmt[x]);
			args->n_chars[i2] = x - i;
			i2++;
		}
	}
}
