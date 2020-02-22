/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:00:25 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/22 07:44:25 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define T "Hello Wolrd! %% okay\n"

void		prints(t_config c)
{
	printf("\n\nflag = %c, w = %d, p = %d, spec = %c\n ; i = %d",
		c.flag, c.width, c.precision, c.specifier, c.i);
}

t_config	ft_init_config(va_list *vargs)
{
	t_config	tmp;

	tmp.i = 0;
	tmp.ret = 0;
	tmp.flag = 0;
	tmp.vargs = vargs;
	tmp.width = 0;
	tmp.precision = 0;
	tmp.specifier = 0;
	return (tmp);
}

void		ft_parse(char *format, t_config *con)
{
	con->i++;
	if (format[con->i] == '-' || format[con->i] == '0')
		con->flag = format[con->i++];
	ft_width(format, con);
	ft_precision(format, con);
	ft_specifier(format, con);
	prints(*con);
}

int			ft_printf(char const *format, ...)
{
	va_list		vargs;
	t_config	con;

	con = ft_init_config(&vargs);
	va_start(vargs, format);
	while (format[con.i])
	{
		if (format[con.i] == '%')
			ft_parse((char *)format, &con);
		else
			ft_putchar(format[con.i++]);
	}
	va_end(vargs);
	return (con.ret);
}

int			main(void)
{
	printf(T);
	ft_printf(T);
}
