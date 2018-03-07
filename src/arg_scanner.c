/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_scanner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:18:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/07 08:28:19 by rzarate          ###   ########.fr       */
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

static	int	check_flags(char *fmt, int x, t_mst *args, int i2)
{
	int x2;

	x2 = 0;
	while (fmt[x] == '#' || fmt[x] == '0' || fmt[x] == '-' || fmt[x] == '+' || fmt[x] == ' ')
	{
		x2++;
		x++;
	}
	args->flags[i2] = ft_strnew(x2);
	while (--x2 >= 0)
		args->flags[i2][x2] = fmt[x - x2];
	return(ft_strlen(args->flags[i2]));
}

static	int	check_mfw(char *fmt, int x, t_mst *args, int i2)
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

static	int	check_precision(char *fmt, int x, t_mst *args, int i2)
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
		tmp = ft_strsub(fmt, x - x2 + 1, x2);
		args->precision[i2] = ft_atoi(tmp);
		free(tmp);
		return (n_digits(args->precision[i2]));
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

static	int	check_mod(char *fmt, int x, t_mst *args, int i2)
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

void	arg_scanner(char *fmt, t_mst *args, int n)
{
	size_t	i;
	int	x;
	int i2;

	i = -1;
	i2 = 0;
	args->flags = (char **)ft_memalloc(sizeof(char *) *n);
	args->mfw = (int *)ft_memalloc(sizeof(int) * n);
	args->precision = (int *)ft_memalloc(sizeof(int) * n);
	args->mod = (int *)ft_memalloc(sizeof(int) *n);
	args->id = ft_strnew(n);
	args->n_chars = (int *)ft_memalloc(sizeof(int) *n);
	while (++i < ft_strlen(fmt) - 1)
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			x = i + 1;
			x += check_flags(fmt, x, args, i2);
			x += check_mfw(fmt, x, args, i2);
			x += check_precision(fmt, x, args, i2);
			x += check_mod(fmt, x, args, i2);
			args->id[i2] = check_ids(fmt[x]);
			args->n_chars[i2] = x - i;
			i2++;
		}
	}
}
