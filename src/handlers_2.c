/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:19:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/20 23:53:03 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_s(t_mst *args, int i, t_uni *d_type)
{
	char	*s;
	wchar_t	*s2;
	int		i2;

	i2 = -1;
	s = ft_strdup(d_type->s);
	if (args->mod[i] == 0 && args->id[i] == 's')
		(!d_type->s) ? s = ft_strdup("(null)") : 0;
	// if (!d_type->s)
	// 	{
	// 		free(s);
	// 		s = NULL;
	// 		s = ft_strdup("(null)");
	// 	}
	else if ((args->mod[i] == 0 && args->id[i] == 'S') ||
			(args->mod[i] == 2 && args->id[i] == 's'))
		s2 = d_type->wcts;
	handle_mfw_s(args, i, &s);
	if ((args->mod[i] == 0 && args->id[i] == 'S') ||
			(args->mod[i] == 2 && args->id[i] == 's'))
	{
		while (++i2 < (int)ft_strlen_wc(s2))
			ft_putchar((char)s2[i]);
		free(s);
		return (ft_strlen_wc(s2));
	}
	if (!d_type->s)
	{
		int n = ft_strlen(s);
		ft_putstr(s);
		free(s);
		return (n);
	}
	return (p_and_f(&s));
}

int	handle_p(t_uni *d_type)
{
	char *s;
	char *tmp;

	s = uitoa_base(d_type->uimt, 16);
	tmp = ft_strjoin("0x", s);
	free(s);
	s = tmp;
	return (p_and_f(&s));
}

int	handle_per(t_mst *args, int i)
{
	char	*s;

	s = ft_strnew(1);
	s[0] = '%';
	handle_mfw(args, i, &s);
	return (p_and_f(&s));
}
