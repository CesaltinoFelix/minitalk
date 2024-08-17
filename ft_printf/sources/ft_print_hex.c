/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:21 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/16 17:18:24 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_hex(unsigned long n, int type)
{
	char	*digits;
	int		len;

	len = 0;
	if (type)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_print_hex(n / 16, type);
	ft_putchar(digits[n % 16]);
	len++;
	return (len);
}
