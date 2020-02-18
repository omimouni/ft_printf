/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:22:29 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/10 18:26:21 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		culen(unsigned int n)
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
char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;

	len = 0;
	len = culen(n);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	*(str + len-- + 1) = '\0';
	if(n == 0)
		*(str) = '0';
	while (n > 0)
	{
		*(str + len) = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (str);
}