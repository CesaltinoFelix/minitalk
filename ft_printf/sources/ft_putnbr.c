/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:52 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/16 17:18:56 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(long n)
{
	long		nbr;
	int			len;

	nbr = 0;
	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
		len++;
	}
	else
		nbr = n;
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
	len++;
	return (len);
}
