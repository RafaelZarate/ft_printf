/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 02:28:25 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	arg_handler(t_mst *args, va_list ap, int i, t_uni *d_type)
{
	if (args->id[i] == 'i' || args->id[i] == 'D' || args->id[i] == 's' || 
			args->id[i] == 'S' || args->id[i] == 'c' || args->id[i] == 'C')
		d_type->imt = va_arg(ap, intmax_t);
	else if (args->id[i] == 'o' || args->id[i] == 'O' || args->id[i] == 'u' || 
			args->id[i] == 'U' || args->id[i] == 'x' || args->id[i] == 'X')
		d_type->uimt = va_arg(ap, uintmax_t);
	

    // printing and returning n of chars printed
    if (args->id[i] == 'c' || args->id[i] == 'C')
		return	(handle_c(args, i, d_type));
    else if (args->id[i] == 's' || args->id[i] == 'S')
		return	(handle_s(args, i, d_type));
    else if (args->id[i] == 'i' || args->id[i] == 'D')
		return	(handle_i(args, i, d_type));
    else if (args->id[i] == 'o')
		return	(handle_o(args, i, d_type));
	else if (args->id[i] == 'u')
		return	(handle_u(args, i, d_type));
	else if (args->id[i] == 'x' || args->id[i] == 'X')
		return	(handle_x(args, i, d_type));
	// p Isn't ready yet
	// else if (args->id[i] == 'p')
	// 	return	(handle_p(args, i, d_type));
	return (0);
}
