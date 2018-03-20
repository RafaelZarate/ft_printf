/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:19:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/19 21:56:47 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_flags(char *fmt, int x, t_mst *args, int i2)
{
	int	x2;

	x2 = 0;
	while (fmt[x] == '#' || fmt[x] == '0' || fmt[x] == '-' ||
			fmt[x] == '+' || fmt[x] == ' ')
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
	return (x2);
}

int		check_mfw(char *fmt, int x, t_mst *args, int i2)
{
	int		x2;
	char	*tmp;

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

int		check_precision(char *fmt, int x, t_mst *args, int i2)
{
	int		x2;
	char	*tmp;

	x2 = 0;
	if (fmt[x] == '.')
	{
		args->dot[i2] = 1;
		x++;
	}
	while (ft_isdigit(fmt[x]))
	{
		x2++;
		x++;
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

int		check_mod(char *fmt, int x, t_mst *args, int i2)
{
	if (fmt[x] == 'h')
	{
		if (fmt[x + 1] == 'h')
		{
			args->mod[i2] = 1;
			return (2);
		}
		args->mod[i2] = 6;
		return (1);
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
		return (1);
	}
	return (0);
}

char	check_ids(char c)
{
	char	*ids;
	char	r;
	int		i;

	i = -1;
	ids = ft_strdup("sSpDioOuUxXcCd%");
	while (ids[++i])
	{
		if (ids[i] == c)
		{
			r = ids[i];
			free(ids);
			return (r);
		}
	}
	return (-1);
}
