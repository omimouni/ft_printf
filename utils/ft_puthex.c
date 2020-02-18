/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:42:56 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/17 16:52:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	csize(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_printhex(char *str, int cap)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] >= 0 && str[i] <= 9)
			ft_putchar(str[i] + '0');
		else
		{
			if(cap)
				ft_putchar(str[i] - 10 + 'A');
			else
				ft_putchar(str[i] - 10 + 'a');
		}
		i++;
	}
	free(str);
}

char	*ft_itoh(unsigned int n)
{
	int		len;
	int		i;
	char	*str;

	len = csize(n);
	i = len;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i--] = '\0';
	while (n > 0)
	{
		str[i] = n % 16;
		n /= 16;
		i--;
	}
	return (str);
}