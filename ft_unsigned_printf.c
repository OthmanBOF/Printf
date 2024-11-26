/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:46:55 by obouftou          #+#    #+#             */
/*   Updated: 2024/11/24 17:18:33 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_printf(unsigned int nb)
{
	int		count;
	char	num;

	count = 0;
	if (nb > 9)
	{
		count = count + ft_unsigned_printf(nb / 10);
		count = count + ft_unsigned_printf(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		num = nb + 48;
		count = count + write(1, &num, 1);
	}
	return (count);
}
