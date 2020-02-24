/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:29 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/23 18:55:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(char *format, t_config *con)
{
	int	sum;

	if (format[con->i] == '*')
	{
		con->width = va_arg(*(con->vargs), int);
		if (con->width < 0)
		{
			con->flag = '-';
			con->width *= -1;
		}
		con->i++;
	}
	else
	{
		sum = 0;
		while (format[con->i] == '-' || format[con->i] == '0')
			con->i++;
		while (format[con->i] >= '0' && format[con->i] <= '9')
			sum = (sum * 10) + (format[con->i++] - '0');
		con->width = sum;
	}
}

void	ft_precision(char *format, t_config *con)
{
	int	sum;

	if (format[con->i] == '.')
	{
		sum = 0;
		con->i++;
		if (format[con->i++] == '*')
			con->precision = va_arg(*(con->vargs), int);
		else
		{
			con->i--;
			while (format[con->i] >= '0' && format[con->i] <= '9')
				sum = sum * 10 + (format[con->i++] - '0');
			con->precision = sum;
		}
		con->has_precision = 1;
		if (con->precision < 0)
			con->has_precision = 0;
	}
}

void	ft_specifier(char *format, t_config *con)
{
	if (format[con->i] == 'd' || format[con->i] == 'c' ||
		format[con->i] == 's' || format[con->i] == 'u' ||
		format[con->i] == 'x' || format[con->i] == 'X' ||
		format[con->i] == 'i' || format[con->i] == '%' ||
		format[con->i] == 'p')
		con->specifier = format[con->i++];
}

void	ft_reader(char *format, t_config *con)
{
	ft_width(format, con);
	ft_precision(format, con);
	ft_specifier(format, con);
}
