/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:30:13 by obouftou          #+#    #+#             */
/*   Updated: 2024/11/24 17:13:47 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptrpf(unsigned long n)
{
	int		count;
	char	num;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_printptrpf(n / 16);
		count = count + ft_printptrpf(n % 16);
	}
	else
	{
		if (n <= 9)
			num = n + 48;
		else
			num = n - 10 + 97;
		count = count + write(1, &num, 1);
	}
	return (count);
}

int	ft_putadress_printf(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 2;
	n = (unsigned long)ptr;
	write (1, "0x", 2);
	return (ft_printptrpf(n) + len);
}
