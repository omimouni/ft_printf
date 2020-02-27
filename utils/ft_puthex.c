/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:42:56 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/27 11:22:29 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		ft_csize(size_t n)
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

void	ft_printhex(char *str, int cap, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (str[i] >= 0 && str[i] <= 9)
			ft_putchar(str[i] + '0');
		else
		{
			if (cap)
				ft_putchar(str[i] - 10 + 'A');
			else
				ft_putchar(str[i] - 10 + 'a');
		}
		i++;
	}
}

char	*ft_itoh(size_t n)
{
	int		len;
	int		i;
	char	*str;

	len = ft_csize(n);
	i = n == 0 ? 1 : len;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i--] = '\0';
	while (n > 0)
	{
		str[i] = n % 16;
		n /= 16;
		i--;
	}
	if (n == 0)
		str[i] = 0;
	return (str);
}

void	ft_puthex(size_t n, int cap)
{
	int	tmp;

	if (n/16 > 0)
		ft_puthex(n/16, cap);
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