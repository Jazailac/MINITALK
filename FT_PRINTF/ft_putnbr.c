/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:33:07 by jazailac          #+#    #+#             */
/*   Updated: 2024/12/09 21:51:00 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	int	readed;

	readed = 0;
	if (nb < 0)
	{
		readed += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		readed += ft_putchar(nb + '0');
	else
	{
		readed += ft_putnbr(nb / 10);
		readed += ft_putchar((nb % 10) + '0');
	}
	return (readed);
}
