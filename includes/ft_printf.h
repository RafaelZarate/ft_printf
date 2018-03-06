/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:41:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/06 02:17:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../src/libft/libft.h"

typedef	struct	s_arg
{
	int		n_chars;
	char	id;
	int		flag;
	int		*mods;
	
}				t_arg;

int	ft_printf(const char *format, ...);
int	arg_handler(char *fmt, int i, va_list ap);

# endif
