/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 02:47:04 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/10 04:13:08 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		set_sign(unsigned int *tmp, int n)
{
	if(n < 0)
	{
		*tmp = -n;
		return (1);
	}
	*tmp = (unsigned int)n;
	return (0);
}

int		clen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{		
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;
	int				sign;

	len = 0;
	sign = set_sign(&tmp, n);
	len = clen(tmp);
	if (!(str = (char *)malloc((len + sign + 1) * sizeof(char))))
		return (NULL);
	*(str + len-- + sign + 1) = '\0';
	if(sign)
		*str = '-';
	while (tmp > 0)
	{
		*(str + len + sign) = tmp % 10 + '0';
		len--;
		tmp /= 10;
	}
	if(n == 0)
		*(str + sign) = '0';
	return (str);
}
