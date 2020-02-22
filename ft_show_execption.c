/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_execption.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:29:18 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/22 13:47:44 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_pointer(t_config *con)
{
	int		i;
	char	*str;
	int		length;

	str = NULL;
	str = ft_itoh(va_arg(*(con->vargs), size_t));
	length = ft_strlen(str);
	i = 0;
	if (con->flag == 0)
		while(i++ < con->width - length - 2)
			ft_putchar(' ');
	ft_putstr("0x");
	ft_printhex(str, 0, length);
	if (con->flag == '-')
		while(i++ < con->width - length - 2)
			ft_putchar(' ');
}

void	ft_show_string(t_config *con)
{
	char	*str;
	int		i;
	int		length;

	str = va_arg(*(con->vargs), char *);
	length = str == NULL ? 6 : ft_strlen(str);
	i = 0;
	if (con->flag == 0)
		while(i++ < con->width - length)
			ft_putchar(' ');
	if (str == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(str);
	if (con->flag == '-')
		while(i++ < con->width - length)
			ft_putchar(' ');
	
}