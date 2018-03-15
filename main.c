/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 05:57:04 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int i = 345643;
	int c = 110;
	char *s = "JEJETL";
	// char *s = "TEST";

	int n2 = printf("PRINTF: %+10i, %10c, %#-14x %15s\n", i, c, i, s);
	int n = ft_printf("FT_PRI: %+10i, %10c, %#-14x %15s\n", i, c, i, s);

	printf("%d, %d", n, n2);
	return (1);
}
