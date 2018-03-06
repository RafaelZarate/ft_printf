/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 04:26:27 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"

typedef	struct	s_mst
{
	int		*n_chars;
	char	*id;
	int		*flag;
	int		**mods;
}				t_mst;

int				ft_printf(const char *format, ...);
int				arg_handler(t_mst *args, va_list ap, int i);
void			arg_scanner(char *fmt, t_mst *args, int n);

#endif
