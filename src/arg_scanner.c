/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_scanner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:18:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 23:15:41 by rzarate          ###   ########.fr       */
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
			while (args->id[i2] == 0)
			{
				if (fmt[x] == '#' || fmt[x] == '0' || fmt[x] == '-' || fmt[x] == '+' || fmt[x] == ' ')
					x += check_flags(fmt, x, args, i2);
				else if (fmt[x] >= '1' && fmt[x] <= '9')
					x += check_mfw(fmt, x, args, i2);
				else if (fmt[x] == '.')
				{
					if (args->precision[i2] == 0)
						x += check_precision(fmt, x, args, i2);
					else
						x++;
				}
				else if ((fmt[x] == 'h' && fmt[x + 1] == 'h') || fmt[x] == 'j' ||
						(fmt[x] == 'l' && fmt[x + 1] == 'l') || fmt[x + 1] == 'l' ||
						fmt[x] == 'z')
					x += check_mod(fmt, x, args, i2);
				else
				{
					args->id[i2] = check_ids(fmt[x]);
					args->n_chars[i2] = x - i;
					if (args->id[i2] == -1)
					{
						args->n_chars[i2]--;
						x--;
					}
					i2++;
				}
			}
		}
	}
}
