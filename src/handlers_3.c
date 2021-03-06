/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:45:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/21 21:45:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_plus_i(t_mst *args, char **s, int len, int i)
{
	char	*tmp;
	int		x;

	x = 0;
	if (len < 1)
	{
		tmp = ft_strjoin("+", *s);
		free(*s);
		*s = tmp;
	}
	else
	{
		if (args->zero[i] == 1)
			(*s)[0] = '+';
		else if (args->zero[i] == 0)
		{
			while (!ft_isdigit(*s[x]))
				x++;
			*(s)[--x] = '+';
		}
	}
}

void	handle_space_i(t_mst *args, char **s, int i)
{
	char	*tmp;

	if (args->mfw[i] == 0)
	{
		tmp = ft_strjoin(" ", *s);
		free(*s);
		*s = tmp;
	}
	else
		*s[0] = ' ';
}

void	handle_mfw_i(t_mst *args, int i, char **s, int neg)
{
	char	*s2;
	int		i2;

	i2 = -1;
	if (args->mfw[i] - (int)ft_strlen(*s) > 0)
	{
		s2 = ft_strnew(args->mfw[i] - (int)ft_strlen(*s));
		if (args->zero[i] == 1 && args->minus[i] == 0)
		{
			while (++i2 < args->mfw[i] - (int)ft_strlen(*s))
				s2[i2] = '0';
			(neg == 1) ? (s2)[0] = '-' : 0;
			(neg == 1) ? (*s)[0] = '0' : 0;
			*s = ft_strjoinf(&s2, s, 3);
		}
		else
		{
			while (++i2 < args->mfw[i] - (int)ft_strlen(*s))
				s2[i2] = ' ';
			if (args->minus[i] == 1)
				*s = ft_strjoinf(s, &s2, 3);
			else
				*s = ft_strjoinf(&s2, s, 3);
		}
	}
}

void	handle_mfw_s(t_mst *args, int i, char **s)
{
	int		len;
	char	*s2;
	int		i2;

	i2 = -1;
	len = args->mfw[i] - (int)ft_strlen(*s);
	if (len > 0)
	{
		s2 = ft_strnew(len);
		while (++i2 < len)
			s2[i2] = ' ';
		if (args->minus[i] == 1)
			*s = ft_strjoinf(s, &s2, 3);
		else
			*s = ft_strjoinf(&s2, s, 3);
	}
}

void	handle_mfw_oux(t_mst *args, int i, char **s)
{
	int		len;
	char	*s2;
	int		i2;

	i2 = -1;
	len = args->mfw[i] - (int)ft_strlen(*s);
	if (len > 0)
	{
		s2 = ft_strnew(len);
		if (args->zero[i] == 1 && args->minus[i] == 0)
		{
			while (++i2 < len)
				s2[i2] = '0';
			if (args->id[i] == 'x' && args->hash[i] == 1)
				switch_xo(s, &s2);
			*s = ft_strjoinf(&s2, s, 3);
		}
		else
		{
			while (++i2 < len)
				s2[i2] = ' ';
			mfw_oux_helper(args, s, &s2, i);
		}
	}
}
