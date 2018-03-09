/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/09 09:27:44 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	// char	c = 'r';
	// long	int	i = 10;
	// char	i2 = 110;

	int n = ft_printf("%s", "LOL");
	// int n2 = printf("%+10li %-1hhx %-1x %c\n", i, i2, i2, c);
	ft_putchar('\n');
	n++;//n2+=1;
	return (1);
}
