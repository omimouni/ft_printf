/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:00:25 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/22 14:05:22 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define T "s%xn\n", 10

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
	tmp.has_precision = 0;
	return (tmp);
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
		{
			ft_putchar(format[con.i++]);
			con.ret++;
		}
	}
	va_end(vargs);
	return (con.ret);
}

int			main(void)
{
	int	r;
	int	f;
	r = printf(T);
	f = ft_printf(T);

	printf("\n-------\n%d %d\n",r, f);
}
