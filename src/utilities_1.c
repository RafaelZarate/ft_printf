/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:23:37 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/14 12:56:21 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_args(char *fmt)
{
	size_t i;
	int	c;

	i = -1;
	c = 0;
	while (++i < ft_strlen(fmt) - 1)
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
			c++;
	}
	return (c);
}
