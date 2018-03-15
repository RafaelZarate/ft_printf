/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 07:59:10 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	// unsigned int i = -114;
	char *s = "TEST";

	int n2 = printf("PRINTF: %s %10s %-10s.\n", s, s, s);
	int n = ft_printf("FT_PRI: %s %10s %-10s.\n", s, s, s);

	printf("%d, %d", n, n2);
	return (1);
}
