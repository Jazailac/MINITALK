/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:30:05 by jazailac          #+#    #+#             */
/*   Updated: 2024/12/11 18:20:26 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_processor(const char c, va_list pa, int readed)
{
	if (c == 'd' || c == 'i')
		readed += ft_putnbr(va_arg(pa, int));
	else if (c == 'c')
		readed += ft_putchar(va_arg(pa, int));
	else if (c == 's')
		readed += ft_putstr(va_arg(pa, char *));
	else if (c == '%')
		readed += ft_putchar('%');
	else if (c == 'u')
		readed += ft_putnbr(va_arg(pa, unsigned int));
	else if (c == 'x' || c == 'X')
		readed += ft_putnbr_base(va_arg(pa, unsigned int ), 16, c);
	else if (c == 'p')
	{
		readed += ft_putstr("0x");
		readed += ft_putnbr_base(va_arg(pa, unsigned long), 16, c);
	}
	else
		readed += ft_putchar(c);
	return (va_end(pa), readed);
}

int	ft_printf(const char *str, ...)
{
	int		readed;
	va_list	pa;
	int		i;

	readed = 0;
	i = 0;
	if (!str)
		return (0);
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(pa, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			readed = check_processor(str[i], pa, readed);
		}
		else if (str[i] == '%')
			return (readed);
		else 
			readed += ft_putchar(str[i]);
		i++;
	}
	return (va_end(pa), readed);
}
