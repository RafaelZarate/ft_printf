/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:19:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/28 22:19:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_s(t_mst *args, int i, t_type *d_type)
{
	char	*s;
	wchar_t	*s2;
	int		i2;

	i2 = -1;
	if (args->mod[i] == 0 && args->id[i] == 's')
	{
		(!ft_strlen(d_type->s)) ? s = ft_strdup("(null)") : 0;
		(ft_strlen(d_type->s)) ? s = ft_strdup(d_type->s) : 0;
	}
	else if ((args->mod[i] == 0 && args->id[i] == 'S') ||
			(args->mod[i] == 2 && args->id[i] == 's'))
	{
		s2 = d_type->wcts;
		if (!ft_strlen_wc(s2))
			s = ft_strdup("(null)");
		else
		{
			s = ft_strnew(ft_strlen_wc(s2));
			while (++i2 < (int)ft_strlen_wc(s2))
				s[i2] = (char)s2[i2];
		}
	}
	handle_mfw_s(args, i, &s);
	return (p_and_f(&s));
}

int	handle_p(t_mst *args, int i, t_type *d_type)
{
	char *s;
	char *tmp;

	s = uitoa_base(d_type->uimt, 16);
	tmp = ft_strjoin("0x", s);
	free(s);
	s = tmp;
	handle_mfw_s(args, i, &s);
	return (p_and_f(&s));
}

int	handle_per(t_mst *args, int i)
{
	char	*s;

	s = ft_strnew(1);
	s[0] = '%';
	handle_mfw_s(args, i, &s);
	return (p_and_f(&s));
}
