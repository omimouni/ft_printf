/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:27:11 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/24 14:26:08 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read_string(char **str, int *length, t_config *con)
{
	size_t	tmp;

	tmp = 0;
	if (con->specifier == 'd' || con->specifier == 'i')
		*str = ft_itoa(va_arg(*(con->vargs), int));
	else if (con->specifier == 'u')
		*str = ft_uitoa(va_arg(*(con->vargs), unsigned int));
	else if (con->specifier == 'X' || con->specifier == 'x')
	{
		tmp = va_arg(*(con->vargs), unsigned int);
		*str = ft_itoh(tmp);
	}
	*length = ft_strlen(*str);
	if (con->specifier == 'X' || con->specifier == 'x')
		*length = ft_csize(tmp);
}

void	ft_presion_zeroes(int *n_zeroes, int *length, char sign,
							t_config *con)
{
	int	s;

	*n_zeroes = 0;
	s = sign == '-' ? 1 : 0;
	if (con->precision >= con->width)
	{
		con->width = con->precision + s;
		con->flag = '0';
	}
	else
	{
		if (con->has_precision)
		{
			*n_zeroes = con->precision - *length >= 0 ?
						con->precision - *length : 0;
			if (sign == '-' && con->precision > *length - s)
				*n_zeroes += 1;
			*length = *length + *n_zeroes;
			if (con->flag == '0')
				con->flag = 0;
		}
	}
}

void	ft_left_print(char sign, t_config *con, int length)
{
	int	i;
	int	s;

	i = 0;
	s = sign == '-' ? 1 : 0;
	if (con->flag == '0')
	{
		if (sign == '-')
			ft_putchar('-');
		while (i++ < con->width - length)
			ft_putchar('0');
	}
	else if (con->flag == 0)
		while (i++ < con->width - length)
			ft_putchar(' ');
}

void	ft_presion_print(char **str, t_config *con, int n_zeroes, int length)
{
	int	i;

	if (*str[0] == '-' && (con->flag == '0'))
		(*str)++;
	if (con->precision < con->width)
	{
		if (*str[0] == '-')
		{
			ft_putchar('-');
			(*str)++;
		}
		i = 0;
		while (i++ < n_zeroes)
			ft_putchar('0');
	}
	if ((con->specifier == 'd' || con->specifier == 'i' 
		|| con->specifier == 'u'))
		ft_putstr(*str);
	else if (con->specifier == 'x')
		ft_printhex(*str, 0, length - n_zeroes);
	else if (con->specifier == 'X')
		ft_printhex(*str, 1, length - n_zeroes);
	else if (con->specifier == '%')
		ft_putchar('%');
	else if (con->specifier == 'c')
		ft_putchar(va_arg(*(con->vargs), int));
}

void	ft_remove_zeroes(t_config *con, char **str, int length)
{
	int	i;

	i = 0;
	if (con->has_precision && con->precision == 0
		&& length == 1 && (*str[i] == '0' || *str[i] == 0))
	{
		if (*str[i] == '0')
			*str[i] = ' ';
		if (con->width == 0)
		{
			free(*str);
			*str = "";
			con->ret--;
		}
	}
}

void	ft_show(t_config *con)
{
	char	*str;
	int		length;
	int		i;
	int		n_zeroes;

	if (con->specifier == '%' || con->specifier == 'c')
	{
		con->has_precision = 0;
		con->precision = 0;
	}
	ft_read_string(&str, &length, con);
	ft_presion_zeroes(&n_zeroes, &length, str[0], con);
	ft_remove_zeroes(con, &str, length);
	if (con->width > length)
		con->ret += con->width;
	else
		con->ret += length;
	ft_left_print(str[0], con, length);
	ft_presion_print(&str, con, n_zeroes, length);
	i = 0;
	if (con->flag == '-')
		while (i++ < con->width - length)
			ft_putchar(' ');
}
