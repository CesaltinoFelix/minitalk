/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:29 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/16 17:18:32 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int					len;
	unsigned long		setpoint;

	len = 0;
	if (!ptr)
	{
		len += ft_putstr("(nil)");
	}
	else
	{
		setpoint = (unsigned long)ptr;
		len += ft_putstr("0x");
		len += ft_print_hex(setpoint, 0);
	}
	return (len);
}
