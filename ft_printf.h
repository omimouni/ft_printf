/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:00:48 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/23 14:53:33 by omimouni         ###   ########.fr       */
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
	int			has_precision;
	va_list		*vargs;
}				t_config;

int				ft_printf(char const *format, ...);
void			ft_parse(char *format, t_config *con);
void			ft_reader(char *format, t_config *con);
void			ft_show(t_config *con);
void			ft_show_pointer(t_config *con);
void			ft_show_string(t_config *con);
void			ft_show_hex(t_config *con);
#endif
