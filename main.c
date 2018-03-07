/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 23:31:05 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int n = ft_printf("LOL & %u\n", -45678);
	int n2 = printf("LOL & %u\n", -45678);
	ft_putchar('\n');
	printf("ft_printf: %i\tprintf: %i", n, n2);
	return (1);
}
