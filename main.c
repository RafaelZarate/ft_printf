/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/10 04:30:24 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	// char	c = 'r';
	long i = 4775807098;
	// char	i2 = 110;

	// ft_printf("%lqi\n", i);
    // ft_printf("%li\n", i);
	ft_printf("%li\n", i);
	printf("%li\n", i);
    // printf("%ls\n", i);

	// int n2 = printf("%+10li %-1hhx %-1x %c\n", i, i2, i2, c);
	return (1);
}
