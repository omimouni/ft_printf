/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:52:53 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/24 14:01:28 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_hex(t_config *con)
{
	unsigned int	tmp;
	int				length;
	char			*str;
	int				cap;
	int				i;
	int				n_zeroes;

	tmp = va_arg(*(con->vargs), unsigned int);
	str = ft_itoh(tmp);
	length = ft_csize(tmp);
	cap = con->specifier == 'x' ? 0 : 1;
	n_zeroes = 0;
	if (con->precision < 0)
	{
		if (con->flag == '0' && con->width > 0)
		{
			con->has_precision = 1;
			con->precision *= -1;
			if (con->flag == '0')
			{
				con->precision = con->width;
				con->has_precision = 1;
				n_zeroes = con->width;
			}
		}
		else
		{
			con->has_precision = 0;
			con->precision = 0;
		}
	}
	if (con->precision < con->width && con->has_precision && con->flag == '0')
		con->flag = 0;
	if (con->precision)
		n_zeroes = con->precision - length > 0 ?
					con->precision - length : 0;
	i = 0;
	while (i++ < con->width - length - n_zeroes &&
			(con->flag == '0' || con->flag == 0))
	{
		if (con->flag == '0')
			ft_putchar('0');
		if (con->flag == 0)
			ft_putchar(' ');
		con->ret++;
	}
	if (con->precision >= con->width && con->precision != 0)
	{
		con->width = con->precision;
		con->flag = '0';
		con->has_precision = 0;
	}
	i = 0;
	while (i++ < n_zeroes)
		ft_putchar('0');
	if (con->has_precision && con->precision == 0
		&& length == 1 && str[0] == 0)
	{
		if (con->width != 0)
			ft_putchar(' ');
		else
			length--;
	}
	else
		ft_printhex(str, cap, length);
	i = 0;
	while (i++ < con->width - length - n_zeroes && con->flag == '-')
	{
		ft_putchar(' ');
		con->ret++;
	}
	con->ret += length + n_zeroes;
}