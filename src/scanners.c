/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:19:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 04:26:15 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	check_ids(char c)
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

int	check_flags(char *fmt, int x, t_mst *args, int i2)
{
	int x2;

	x2 = 0;
	while (fmt[x] == '#' || fmt[x] == '0' || fmt[x] == '-' || fmt[x] == '+' || fmt[x] == ' ')
	{
		if (fmt[x] == '#')
			args->hash[i2] = 1;
		else if (fmt[x] == '0')
			args->zero[i2] = 1;
		else if (fmt[x] == '-')
			args->minus[i2] = 1;
		else if (fmt[x] == '+')
			args->plus[i2] = 1;
		else if (fmt[x] == ' ')
			args->space[i2] = 1;
		x2++;
		x++;
	}
	return(x2);
}

int	check_mfw(char *fmt, int x, t_mst *args, int i2)
{
	int x2;
	char *tmp;

	x2 = 0;
	while (ft_isdigit(fmt[x]))
	{
		x2++;
		x++;
	}
	if (x2 > 0)
	{
		tmp = ft_strsub(fmt, x - x2, x2);
		args->mfw[i2] = ft_atoi(tmp);
		free(tmp);
		return (n_digits(args->mfw[i2]));
	}
	else
		return (0);
}

int	check_precision(char *fmt, int x, t_mst *args, int i2)
{
	int x2;
	char *tmp;

	x2 = 0;
	if (fmt[x] == '.')
	{
		x++;
		while (ft_isdigit(fmt[x]))
		{
			x2++;
			x++;
		}
	}
	if (x2 > 0)
	{
		tmp = ft_strsub(fmt, x - x2, x2);
		args->precision[i2] = ft_atoi(tmp);
		free(tmp);
		return (x2 + 1);
	}
	else
		return (0);
}

/*
 **	hh = 1
 **	l = 2
 **	ll = 3
 **	j = 4
 **	z = 5
*/

int	check_mod(char *fmt, int x, t_mst *args, int i2)
{
	if (fmt[x] == 'h' && fmt[x + 1] == 'h')
	{
		args->mod[i2] = 1;
		return (2);
	}
	else if (fmt[x] == 'l')
	{
		if (fmt[x + 1] == 'l')
		{
			args->mod[i2] = 3;
			return (2);
		}
		args->mod[i2] = 2;
		return (1);
	}
	else if (fmt[x] == 'j')
	{
		args->mod[i2] = 4;
		return (1);
	}
	else if (fmt[x] == 'z')
	{
		args->mod[i2] = 5;
		return (0);
	}
	return (0);
}