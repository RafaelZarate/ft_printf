/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:23:37 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/20 11:52:36 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_args(char *fmt)
{
	size_t	x;
	int		c;

	x = -1;
	c = 0;
	while (++x < ft_strlen(fmt) - 1)
	{
		if (fmt[x] == '%')
		{
			x++;
			while (fmt[x] && (fmt[x] == '#' || fmt[x] == '0' || fmt[x] == '-' ||
					fmt[x] == '+' || fmt[x] == ' '))
				x++;
			while (fmt[x] && ft_isdigit(fmt[x]))
				x++;
			(fmt[x] && fmt[x] == '.') ? x++ : 0;
			while (fmt[x] && (ft_isdigit(fmt[x])))
				x++;
			(fmt[x + 1] && ((fmt[x] == 'h' && fmt[x + 1] == 'h') ||
					(fmt[x] == 'l' && fmt[x + 1] == 'l'))) ? x += 2 : 0;
			((fmt[x] == 'l' || fmt[x] == 'j' || fmt[x] == 'z')) ? x++ : 0;
			(fmt[x] && (check_ids(fmt[x]) > -1)) ? c++ : 0;
		}
	}
	return (c);
}

void	struct_initializer(t_mst *args, int n)
{
	args->hash = (int *)ft_memalloc(sizeof(int) * n);
	args->zero = (int *)ft_memalloc(sizeof(int) * n);
	args->minus = (int *)ft_memalloc(sizeof(int) * n);
	args->plus = (int *)ft_memalloc(sizeof(int) * n);
	args->space = (int *)ft_memalloc(sizeof(int) * n);
	args->mfw = (int *)ft_memalloc(sizeof(int) * n);
	args->dot = (int *)ft_memalloc(sizeof(int) * n);
	args->precision = (int *)ft_memalloc(sizeof(int) * n);
	args->mod = (int *)ft_memalloc(sizeof(int) * n);
	args->id = ft_strnew(n);
	args->n_chars = (int *)ft_memalloc(sizeof(int) * n);
}

void	struct_finalizer(t_mst *args)
{
	free(args->hash);
	free(args->zero);
	free(args->minus);
	free(args->plus);
	free(args->space);
	free(args->mfw);
	free(args->precision);
	free(args->mod);
	free(args->id);
	free(args->n_chars);
}

void	i_helper(t_mst *args, int i, char **s)
{
	int neg;
	int len;

	neg = (*s[0] == '-') ? 1 : 0;
	len = args->mfw[i] - (int)ft_strlen(*s);
	handle_mfw_i(args, i, s, neg);
	if (args->plus[i] == 1 && neg == 0)
		handle_plus_i(args, s, len, i);
	else if (args->space[i] == 1)
	{
		if (args->mfw[i] == 0 && neg == 0)
			*s = ft_strjoin(" ", *s);
		else if (args->mfw[i] != 0 && neg == 0)
			*s[0] = ' ';
	}
}

int		p_and_f(char **s)
{
	int	len;
	
	len = ft_strlen(*s);
	ft_putstr(*s);
	free(*s);
	return (len);
}