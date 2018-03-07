/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/07 02:49:50 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	wchar_t *s = L"LOL";
	int n = ft_printf("LOL & %S\n", s);
	int n2 = printf("LOL & %S\n", s);
	ft_putchar('\n');
	printf("ft_printf: %i\tprintf: %i", n, n2);
	while (1)
		n++;
	return (1);
}
