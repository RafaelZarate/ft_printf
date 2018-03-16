/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:23:37 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 23:15:08 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_args(char *fmt)
{
	size_t i;
	int	c;

	i = -1;
	c = 0;
	while (++i < ft_strlen(fmt) - 1)
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
			c++;
	}
	return (c);
}

void	handle_plus_i(t_mst *args, char **s, int len)
{
	char *tmp;
	
	tmp = *s;
	if (len < 1)
		tmp = ft_strjoin("+", tmp);
	else
	{
		if (args->zero[0] == 1)
			tmp[0] = '+';
		else
		{
			int x;

			x = 0;
			while (!ft_isdigit(tmp[x]))
				x++;
			tmp[--x] = '+';
		}
	}
	*s = tmp;
}

void	handle_space_i(t_mst *args, char **s, int i)
{
	char	*tmp;

	tmp = *s;
	if (args->mfw[i] == 0)
		tmp = ft_strjoin(" ", tmp);
	else
		tmp[0] = ' ';
	*s = tmp;
}


void	handle_mfw_i(t_mst *args, int i, char **s, int neg)
{
	char *tmp;
	int len;

	tmp = *s;
	len = args->mfw[i] - (int)ft_strlen(tmp);
	if (len > 0)
	{
		char *s2;
		int i2;

		i2 = -1;
		s2 = ft_strnew(len);
		if (args->zero[i] == 1 && args->minus[i] == 0)
		{
			while (++i2 < len)
				s2[i2] = '0';
			if (neg == 1)
			{
				s2[0] = '-';
				tmp[0] = '0';
			}
			*s = ft_strjoin(s2, tmp);
		}
		else
		{
			while (++i2 < len)
				s2[i2] = ' ';
			if (args->minus[i] == 1)
				*s = ft_strjoin(tmp, s2);
			else
				*s = ft_strjoin(s2, tmp);
		}
	}
}

void	handle_mfw(t_mst *args, int i, char **s)
{
	char *tmp;
	int len;

	tmp = *s;
	len = args->mfw[i] - (int)ft_strlen(tmp);
	if (len > 0)
	{
		char *s2;
		int i2;

		i2 = -1;
		s2 = ft_strnew(len);
		if (args->zero[i] == 1 && args->minus[i] == 0)
		{
			while (++i2 < len)
				s2[i2] = '0';
			*s = ft_strjoin(s2, tmp);
		}
		else
		{
			while (++i2 < len)
				s2[i2] = ' ';
			if (args->minus[i] == 1)
				*s = ft_strjoin(tmp, s2);
			else
				*s = ft_strjoin(s2, tmp);
		}
	}
}

void	struct_initializer(t_mst *args, int n)
{
	args->hash = (int *)ft_memalloc(sizeof(int) * n);
	args->zero = (int *)ft_memalloc(sizeof(int) * n);
	args->minus = (int *)ft_memalloc(sizeof(int) * n);
	args->plus = (int *)ft_memalloc(sizeof(int) * n);
	args->space = (int *)ft_memalloc(sizeof(int) * n);
	args->mfw = (int *)ft_memalloc(sizeof(int) * n);
	args->precision = (int *)ft_memalloc(sizeof(int) * n);
	args->mod = (int *)ft_memalloc(sizeof(int) *n);
	args->id = ft_strnew(n);
	args->n_chars = (int *)ft_memalloc(sizeof(int) *n);
}