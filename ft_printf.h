/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:00:48 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/22 07:46:36 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "utils/ft_utils.h"

typedef struct	s_config{
	int			i;
	int			ret;
	char		flag;
	int			width;
	int			precision;
	char		specifier;
	va_list		*vargs;
}				t_config;

int				ft_printf(char const *format, ...);
void			ft_width(char *format, t_config *con);
void			ft_precision(char *format, t_config *con);
void			ft_specifier(char *format, t_config *con);
void			ft_putn(t_config *con);
void			ft_putstr(char *str);
#endif
