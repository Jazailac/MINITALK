/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:33:13 by jazailac          #+#    #+#             */
/*   Updated: 2024/12/11 18:09:48 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;
	int	readed;

	i = 0;
	readed = 0;
	if (!str)
	{
		readed += ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		readed += ft_putchar(str[i]);
		i++;
	}
	return (readed);
}
