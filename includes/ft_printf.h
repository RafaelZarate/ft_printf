/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/07 06:50:19 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"

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
int				arg_handler(t_mst *args, va_list ap, int i);
void			arg_scanner(char *fmt, t_mst *args, int n);

#endif
