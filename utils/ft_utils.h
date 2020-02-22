/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:12:06 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/22 07:47:24 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_strlen(char *str);
char	*ft_itoh(unsigned int n);
void	ft_printhex(char *str, int cap);
#endif
