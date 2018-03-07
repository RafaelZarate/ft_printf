/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_scanner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:18:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/07 04:01:13 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	check_ids(char c)
{
	char ids[14];
	int i;

	i = -1;
	ids[0] = 's';
	ids[1] = 'S';
	ids[2] = 'p';
	ids[3] = 'D';
	ids[4] = 'i';
	ids[5] = 'o';
	ids[6] = 'O';
	ids[7] = 'u';
	ids[8] = 'U';
	ids[9] = 'x';
	ids[10] = 'X';
	ids[11] = 'c';
	ids[12] = 'C';
	ids[13] = '\0';
	while (ids[++i])
	{
		if (ids[i] == c)
			return (ids[i]);
	}
	return (-1);
}

/*
 **	hh = 1
 **	l = 2
 **	ll = 3
 **	j = 4
 **	z = 5
*/

static	int	check_flags(int x, char *s)
{
	if (s[x] == 'h' && s[x + 1] == 'h')
		return (1);
	else if (s[x] == 'l')
	{
		if (s[x + 1] == 'l')
			return 3;
		return (2);
	}
	else if (s[x] == 'j')
		return (4);
	else if (s[x] == 'z')
		return (5);
	return (0);
}

void	arg_scanner(char *fmt, t_mst *args, int n)
{
	size_t	i;
	int	x;
	int i2;

	i = -1;
	x = 0;
	i2 = 0;
	args->n_chars = (int *)ft_memalloc(sizeof(int) *n);
	args->id = ft_strnew(n);
	args->flag = (int *)ft_memalloc(sizeof(int) *n);
	args->mods = (int **)ft_memalloc(sizeof(int *) *n);
	while (++i < ft_strlen(fmt))
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			x = i + 1;
			while (check_ids(fmt[x]) == -1)
			{
				args->flag[i2] = check_flag(x, fmt);
				x++;
			}
			args->id[i2] = check_ids(fmt[x]);
			args->n_chars[i2] = x - i;
			i2++;
		}
	}
}