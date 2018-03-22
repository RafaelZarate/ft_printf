/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/21 23:22:51 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_and_f(char **s)
{
	int	len;

	len = ft_strlen(*s);
	ft_putstr(*s);
	ft_strdel(s);
	return (len);
}

int		check_valid(t_mst *args, int c_a)
{
	int i;

	i = -1;
	while (++i < c_a)
	{
		if (args->id[i] == -1 || args->dot[i] == 1)
			return (0);
	}
	return (1);
}

void	mfw_oux_helper(t_mst *args, char **s, char **s2, int i)
{
	if (args->minus[i] == 1)
		*s = ft_strjoinf(s, s2, 3);
	else
		*s = ft_strjoinf(s2, s, 3);
}

void	check_flags_ca(int *x, char *fmt)
{
	while (fmt[*x] && (fmt[*x] == '#' || fmt[*x] == '0' || fmt[*x] == '-' ||
		fmt[*x] == '+' || fmt[*x] == ' '))
		*x++;
}
