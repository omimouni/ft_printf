/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:12:06 by omimouni          #+#    #+#             */
/*   Updated: 2020/02/27 11:27:10 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_strlen(char *str);
char	*ft_itoh(size_t n);
void	ft_printhex(char *str, int cap, int length);
int		ft_csize(size_t n);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
int		ft_intlen(unsigned int n);
void	ft_puthex(size_t n, int cap);
#endif
