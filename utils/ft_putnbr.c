/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:22:41 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/27 11:28:43 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_utils.h"

void	ft_putnbr(int n)
{
	unsigned int 	tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		ft_putchar('-');
	}
	if (tmp / 10 > 0)
		ft_putnbr(tmp / 10);
	ft_putchar('0' + tmp % 10);
}

void	ft_putunbr(unsigned int n)
{
	if (n / 10 > 0)
		ft_putunbr(n / 10);
	ft_putchar('0' + n % 10);
}