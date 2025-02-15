/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:32:35 by jazailac          #+#    #+#             */
/*   Updated: 2024/12/09 22:26:51 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nb, unsigned long base, char c)
{
	int		readed;
	char	*set;

	readed = 0;
	set = "0123456789abcdef";
	if (c == 'X')
		set = "0123456789ABCDEF";
	if (nb >= base)
		readed += ft_putnbr_base((nb / base), base, c);
	readed += ft_putchar(set[nb % base]);
	return (readed);
}
