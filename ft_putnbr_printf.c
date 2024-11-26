/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:19:09 by obouftou          #+#    #+#             */
/*   Updated: 2024/11/24 18:15:48 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb *= -1;
		count = count + write(1, "-", 1);
	}
	if (nb > 9)
	{
		count += ft_putnbr_printf(nb / 10);
		count += ft_putnbr_printf(nb % 10);
	}
	else
		count += ft_putchar_printf(nb + '0');
	return (count);
}
