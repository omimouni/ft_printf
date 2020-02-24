/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_execption.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:29:18 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/24 14:09:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_pointer(t_config *con)
{
	int		i;
	char	*str;
	int		length;
	size_t	tmp;

	str = NULL;
	tmp = va_arg(*(con->vargs), size_t);
	str = ft_itoh(tmp);
	length = ft_csize(tmp);
	i = 0;
	if (!tmp && con->has_precision)
		length = 0;
	if (con->flag == 0)
		while(i++ < con->width - length - 2)
			ft_putchar(' ');
	ft_putstr("0x");
	if (tmp != 0)
		ft_printhex(str, 0, length);
	else if (!con->has_precision)
		ft_putchar('0');
	if (con->flag == '-')
		while(i++ < con->width - length - 2)
			ft_putchar(' ');
	if (con->width > length +2)
		con->ret += con->width;
	else
		con->ret += length + 2;
	free(str);
}

void	ft_show_string(t_config *con)
{
	char	*str;
	int		i;
	int		n;
	int		length;

	str = va_arg(*(con->vargs), char *);
	n = 0;
	if (str == NULL)
	{
		str = "(null)";
		n = 1;
	}
	length = ft_strlen(str);
	if (con->precision < length && con->has_precision)
		length = con->precision;
	i = 0;
	if (con->flag == 0)
		while(i++ < con->width - length)
			ft_putchar(' ');
	i = 0;
	if (!con->has_precision)
		con->precision = length;
	while (i < con->precision && str[i])
		ft_putchar(str[i++]);
	i = 0;
	if (con->flag == '-')
		while(i++ < con->width - length)
			ft_putchar(' ');
	if (con->width > length)
		con->ret += con->width;
	else
		con->ret += length;
}