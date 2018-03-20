/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/20 14:56:43 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"

typedef	union	u_mst
{
	int							i;
	short						si;
	unsigned	short			usi;
	unsigned	int				ui;
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
	int		*hash;
	int		*zero;
	int		*minus;
	int		*plus;
	int		*space;
	int		*mfw;
	int		*dot;
	int		*precision;
	int		*mod;
	char	*id;
	int		*n_chars;
}				t_mst;

# define IDS "sSpDioOuUxXcCd%"

/*
** MAIN FUNCTIONS
*/
int				ft_printf(const char *format, ...);

/*
** SCANNING FUNCTIONS
*/
int				check_flags(char *fmt, int x, t_mst *args, int i2);
int				check_mfw(char *fmt, int x, t_mst *args, int i2);
int				check_precision(char *fmt, int x, t_mst *args, int i2);
int				check_mod(char *fmt, int x, t_mst *args, int i2);
char			check_ids(char c);

/*
** HANDLING
*/
int				handle_i(t_mst *args, int i, t_uni *d_type);
int				handle_o(t_mst *args, int i, t_uni *d_type);
int				handle_u(t_mst *args, int i, t_uni *d_type);
int				handle_x(t_mst *args, int i, t_uni *d_type);
int				handle_c(t_mst *args, int i, t_uni *d_type);
int				handle_s(t_mst *args, int i, t_uni *d_type);
int				handle_p(t_uni *d_type);
int				handle_per(t_mst *args, int i);

void			handle_mfw(t_mst *args, int i, char **s);
void			handle_mfw_i(t_mst *args, int i, char **s, int neg);
void			handle_flags_i(t_mst *args, int i, char **s, int len);
void			handle_plus_i(t_mst *args, char **s, int len, int i);
void			handle_space_i(t_mst *args, char **s, int i);
void			handle_pre(t_mst *args, int i, char **s);

/*
** UTILITIES
*/
int				count_args(char *fmt);
int				arg_is_valid(char *fmt, int i);
void			struct_initializer(t_mst *args, int n);
void			struct_finalizer(t_mst *args);
void			i_helper(t_mst *args, int i, char **s);
int				p_and_f(char **s);

#endif
