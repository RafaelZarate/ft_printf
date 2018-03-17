/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_scanner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:18:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/17 14:58:36 by rzarate          ###   ########.fr       */
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
	struct_initializer(args, n);
	while (++i < ft_strlen(fmt) - 1)
	{
		if (fmt[i] == '%')
		{
			x = i + 1;
			x += check_flags(fmt, x, args, i2);
			x += check_mfw(fmt, x, args, i2);
			if (fmt[x] == '.')
				x += check_precision(fmt, x, args, i2);
			x += check_mod(fmt, x, args, i2);
			args->id[i2] = check_ids(fmt[x]);
			args->n_chars[i2] = x - i;
			if (args->id[i2] == -1)
			{
				args->n_chars[i2]--;
				x--;
			}
			else
				i2++;
			i += x;
		}
	}
}
