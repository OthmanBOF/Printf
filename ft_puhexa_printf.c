/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puhexa_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:17:00 by obouftou          #+#    #+#             */
/*   Updated: 2024/11/24 17:43:44 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_printf(unsigned int n, const char f)
{
	int		count;
	char	num;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_puthexa_printf((n / 16), f);
		count = count + ft_puthexa_printf((n % 16), f);
	}
	else
	{
		if (n <= 9)
			num = n + '0';
		else
		{
			if (f == 'x')
				num = n - 10 + 97;
			else if (f == 'X')
				num = n - 10 + 65;
		}
		count = count + write(1, &num, 1);
	}
	return (count);
}
