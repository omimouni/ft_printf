/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:29:01 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/18 22:16:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show(char *str, char spec)
{
	if(spec == 'd' || spec == 'i')
		ft_putstr(str);
	else if (spec == 'x')
		ft_printhex(str, 0);
	else if (spec == 'X')
		ft_printhex(str, 1);
}

void	read_str(char spec, va_list *vargs, char **str, int *len)
{
	if(spec == 'd' || spec == 'i')
		*str = ft_itoa(va_arg(*(vargs), int));
	else if (spec == 'x' || spec == 'X')
		*str = ft_itoh(va_arg(*(vargs), unsigned int));
	*len = ft_strlen(*str);
}

void	ft_putn(t_config *con)
{
	char 	*str;
	int		len;
	int		i;
	int		j;
	int		width;

	read_str(con->specifier, con->vargs, &str, &len);
	i = 0;
	width = con->width;
	if (con->precision > con->width)
	{
		width = con->precision;
		con->flag = '0';
	}
	if(con->flag != '-')
	{
		while (width - len > i++)
			if (con->flag == '0' && (con->width - con->precision > 0))
				ft_putchar('0');
			else
				ft_putchar(' ');
	}
	ft_show(str, con->specifier);
	if(con->flag == '-')
		while (width - len > i++)
			ft_putchar(' ');
}