/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:42:56 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/27 13:43:18 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		ft_hexlen(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(size_t n, int cap)
{
	int	tmp;

	if (n / 16 > 0)
		ft_puthex(n / 16, cap);
	tmp = n % 16;
	if (tmp >= 0 && tmp <= 9)
		ft_putchar('0' + tmp);
	else
	{
		if (cap)
			ft_putchar(tmp - 10 + 'A');
		else
			ft_putchar(tmp - 10 + 'a');
	}
}
