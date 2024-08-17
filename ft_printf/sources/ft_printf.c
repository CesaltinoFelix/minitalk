/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:02 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/16 17:18:05 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_format(va_list data, const char *s)
{
	if (*s == 'c')
	{
		return (ft_putchar(va_arg(data, int)));
	}
	else if (*s == 's')
		return (ft_putstr(va_arg(data, char *)));
	else if (*s == 'd' || *s == 'i')
		return ((long)ft_putnbr(va_arg(data, int)));
	else if (*s == 'u')
		return (ft_putunsigned(va_arg(data, unsigned int)));
	else if (*s == 'x')
		return (ft_print_hex(va_arg(data, unsigned int), 0));
	else if (*s == 'X')
		return (ft_print_hex(va_arg(data, unsigned int), 1));
	else if (*s == 'p')
		return (ft_print_ptr(va_arg(data, void *)));
	else if (*s == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list		data;
	int			len;

	va_start (data, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_format(data, str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(data);
	return (len);
}
