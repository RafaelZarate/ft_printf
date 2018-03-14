/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:12:08 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/14 13:38:57 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	unsigned char i = 157;

	int n = ft_printf("%hho, %hhu, %hhx, %hhX\n", i, i, i, i);
	int n2 = printf("%hho, %hhu, %hhx, %hhX\n", i, i, i, i);
    

	printf("%d, %d", n, n2);
	return (1);
}
