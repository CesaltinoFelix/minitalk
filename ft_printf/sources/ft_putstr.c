/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:19:11 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/16 17:19:14 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (*s)
	{
		ft_putchar(*s++);
		len++;
	}
	return (len);
}
