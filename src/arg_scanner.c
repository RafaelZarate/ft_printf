/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_scanner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:18:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 04:18:13 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	check_ids(char c)
{
	char *ids;
	int i;
	char r;

	i = -1;
	ids = ft_strnew(13);
	ids = "sSpDioOuUxUcC";
	while (ids[++i])
	{
		if (ids[i] == c)
		{
			r = ids[i];
			free(ids);
			return (r);
		}
	}
	free(ids);
	return (-1);
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
				x++;
			args->id[i2] = check_ids(fmt[x]);
			args->n_chars[i2] = x - i;
			i2++;
		}
	}
}