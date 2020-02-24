/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:17:54 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/23 21:31:17 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints(t_config c)
{
	printf("\n\nflag = %c, w = %d, p = %d, spec = %c\n ; i = %d",
		c.flag, c.width, c.precision, c.specifier, c.i);
}

void	ft_parse(char *format, t_config *con)
{
	con->i++;
	if (format[con->i] == '-' || format[con->i] == '0')
		con->flag = format[con->i++];
	ft_reader(format, con);
	if (con->specifier == 'p')
		ft_show_pointer(con);
	else if (con->specifier == 's')
		ft_show_string(con);
	else if (con->specifier == 'x' || con->specifier == 'X')
		ft_show_hex(con);
	else
		ft_show(con);
}
