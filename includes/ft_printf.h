/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/15 05:01:52 by rzarate          ###   ########.fr       */
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
    wchar_t						wct;
	wchar_t						*wcts;
	void						*p;
}				t_uni;

typedef	struct	s_mst
{
	int 	*hash;
	int 	*zero;
	int 	*minus;
	int 	*plus;
	int 	*space;
	int		*mfw;
	int		*precision;
	int		*mod;
	char	*id;
	int		*n_chars;
}				t_mst;

/* MAIN FUNCTIONS */
int				ft_printf(const char *format, ...);
int				arg_handler(t_mst *args, va_list ap, int i, t_uni *d_type);
void			arg_scanner(char *fmt, t_mst *args, int n);

/* SCANNING FUNCTIONS */
int				check_flags(char *fmt, int x, t_mst *args, int i2);
int				check_mfw(char *fmt, int x, t_mst *args, int i2);
int				check_precision(char *fmt, int x, t_mst *args, int i2);
int				check_mod(char *fmt, int x, t_mst *args, int i2);
char			check_ids(char c);

/* HANDLING */
int				handle_i(t_mst *args, int i, t_uni *d_type);
int				handle_o(t_mst *args, int i, t_uni *d_type);
int				handle_u(t_mst *args, int i, t_uni *d_type);
int				handle_x(t_mst *args, int i, t_uni *d_type);
int				handle_c(t_mst *args, int i, t_uni *d_type);
int				handle_s(t_mst *args, int i, t_uni *d_type);
// int				handle_p(t_mst *args, int i, t_uni *d_type);

/* UTILITIES */
int				count_args(char *fmt);
void			handle_mfw(t_mst *args, int i, char **s);


#endif
