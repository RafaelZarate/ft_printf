/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/09 09:32:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"

typedef	union	u_mst
{
	int							i;
	char						c;
	signed	char				schar;
	unsigned	char			uchar;
	long						lint;
	unsigned	long			ulint;
	long	long				llint;
	unsigned	long	long	ullint;
	intmax_t					imt;
	uintmax_t					uimt;
	ssize_t						sst;
	size_t						st;
	char						*s;
	wchar_t						*wct;
	void						*p;
}				t_uni;

typedef	struct	s_mst
{
	char	**flags;
	int		*mfw;
	int		*precision;
	int		*mod;
	char	*id;
	int		*n_chars;
}				t_mst;

int				ft_printf(const char *format, ...);
int				arg_handler(t_mst *args, va_list ap, int i, t_uni *d_type);
void			arg_scanner(char *fmt, t_mst *args, int n);

#endif
