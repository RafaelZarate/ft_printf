/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/17 20:20:46 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	arg_handler(t_mst *args, va_list ap, int i, t_uni *d_type)
{
	if (args->id[i] == 'i' || args->id[i] == 'd' || args->id[i] == 'D' ||
			args->id[i] == 's' || args->id[i] == 'S' || args->id[i] == 'c' ||
			args->id[i] == 'C')
		d_type->imt = va_arg(ap, intmax_t);
	else if (args->id[i] == 'o' || args->id[i] == 'O' || args->id[i] == 'u' || 
			args->id[i] == 'U' || args->id[i] == 'x' || args->id[i] == 'X' ||
			args->id[i] == 'C' || args->id[i] == 'p')
		d_type->uimt = va_arg(ap, uintmax_t);
	

    // printing and returning n of chars printed
	if (args->id[i] == -1)
		return (0);
    if (args->id[i] == 'c' || args->id[i] == 'C')
		return	(handle_c(args, i, d_type));
    else if (args->id[i] == 's' || args->id[i] == 'S')
		return	(handle_s(args, i, d_type));
    else if (args->id[i] == 'i' || args->id[i] == 'd' || args->id[i] == 'D')
		return	(handle_i(args, i, d_type));
    else if (args->id[i] == 'o')
		return	(handle_o(args, i, d_type));
	else if (args->id[i] == 'u')
		return	(handle_u(args, i, d_type));
	else if (args->id[i] == 'x' || args->id[i] == 'X')
		return	(handle_x(args, i, d_type));
	else if (args->id[i] == '%' || args->id[i] == '%')
		return	(handle_per(args, i));
	// p Isn't ready yet
	else if (args->id[i] == 'p')
		return	(handle_p(d_type));
	return (0);
}

// int	arg_is_valid(char *fmt, int x)
// {
// // 	int id;
// // 	int c;

// // 	id = 0;
// // 	x++;
// // 	while (id == 0)
// // 	{
// // 		if (fmt[x] == '#' || fmt[x] == '0' || fmt[x] == '-' || fmt[x] == '+' || fmt[x] == ' ')
// // 			x += check_flags(fmt, x, args, i2);
// // 		else if (fmt[x] >= '1' && fmt[x] <= '9')
// // 			x += check_mfw(fmt, x, args, i2);
// // 		else if (fmt[x] == '.')
// // 		{
// // 			if (args->precision[i2] == 0)
// // 				x += check_precision(fmt, x, args, i2);
// // 			else
// // 				x++;
// // 		}
// // 		else if ((fmt[x] == 'h' && fmt[x + 1] == 'h') || fmt[x] == 'j' ||
// // 				(fmt[x] == 'l' && fmt[x + 1] == 'l') || fmt[x + 1] == 'l' ||
// // 				fmt[x] == 'z')
// // 			x += check_mod(fmt, x, args, i2);
// // 		else
// // 		{
// // 			args->id[i2] = check_ids(fmt[x]);
// // 			args->n_chars[i2] = x - i;
// // 		}
// // 		if (args->id[i2] == -1)
// // 		{
// // 			args->n_chars[i2]--;
// // 			x--;
// // 		}
// // 		i2++;
// // 	}
// 	fmt[0] = 'x';
// 	x++;
// 	return (1);
// }
