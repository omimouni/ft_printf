/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:05:20 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/27 12:59:53 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_show_nbr_read(t_config *con, int *sign,
							int *length, int *n_zeroes)
{
	long tmp;

	tmp = 0;
	if (con->specifier == 'u')
		tmp = va_arg(*(con->vargs), unsigned int);
	else
		tmp = va_arg(*(con->vargs), int);
	*sign = tmp < 0 ? 1 : 0;
	if (*sign)
		*length = ft_intlen(tmp*-1) + 1;
	else
		*length = ft_intlen(tmp);
	*n_zeroes = 0;
	con->nbr = &tmp;
	con->length = length;
	con->n_zeroes = n_zeroes;
	con->sign = sign;
	return (tmp);
}

int		ft_show_nbr_print_n(t_config *con)
{
	int i;
	int	print_n;

	i = 0;
	print_n = 0;
	if (con->has_precision)
	{
		if (con->precision >= con->width)
		{
			con->flag = '0';
			con->width = con->precision + *con->sign;
		}
		else
		{
			if (con->flag == '0')
				con->flag = 0;
			if (*con->nbr < 0 && con->precision != 0)
				print_n = 1;
			i = 0;
			while (i++ < con->precision - *con->length + *con->sign)
				*(con->n_zeroes) += 1;
		}
	}
	if (print_n)
		return (1);
	return (0);
}

void	ft_show_nbr_flag(t_config *con)
{
	int	i;

	i = 0;
	if (con->flag == 0 || con->flag == '0')
	{
		if (con->flag == 0){
			while (i++ < con->width - *con->length - *con->n_zeroes)
				ft_putchar(' ');
		}
		else
		{
			if (*con->sign)
				ft_putchar('-');
			while (i++ < con->width - *con->length - *con->n_zeroes)
				ft_putchar('0');
		}
	}
}

void	ft_show_print(t_config *con, long tmp, int print_n)
{
	int	i;

	i = 0;
	if (print_n)
		ft_putchar('-');
	while(i++ < *con->n_zeroes)
		ft_putchar('0');
	if ((*con->sign && con->flag == '0') || (print_n && tmp < 0))
		if (tmp == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr(tmp * -1);
	else
	{
		if (con->specifier == 'u')
			ft_putunbr(tmp);
		else
			ft_putnbr(tmp);
	}
}

void	ft_show_nbr(t_config *con)
{
	long	tmp;
	int	length;
	int	sign;
	int	i;
	int	n_zeroes;
	int	print_n;

	tmp = ft_show_nbr_read(con, &sign, &length, &n_zeroes);
	print_n = ft_show_nbr_print_n(con);
	ft_show_nbr_flag(con);
	if (con->has_precision && tmp == 0 && con->precision == 0)
	{
		if (con->width != 0)
			ft_putchar(' ');
		else
			con->ret--;
	}
	else
		ft_show_print(con, tmp, print_n);
	i = 0;
	if (con->flag == '-')
	{
		while (i++ < con->width - length - n_zeroes)
			ft_putchar(' ');
	}
	if (con->width - length > 0)
		con->ret += con->width;
	else
		con->ret += length;
}