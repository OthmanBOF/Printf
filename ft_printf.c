/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:01:57 by obouftou          #+#    #+#             */
/*   Updated: 2024/11/26 11:27:18 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char f, va_list args)
{
	int	count;

	count = 0;
	if (f == 'c')
		count = count + ft_putchar_printf(va_arg(args, int));
	else if (f == 's')
		count = count + ft_putstr_printf(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		count = count + ft_putnbr_printf(va_arg(args, int));
	else if (f == 'p')
		count = count + ft_putadress_printf(va_arg(args, void *));
	else if (f == 'u')
		count = count + ft_unsigned_printf(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		count = count + ft_puthexa_printf(va_arg(args, int), f);
	else if (f == '%')
		count = count + ft_putchar_printf('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (write(1, "", 0) < 0)
			return (-1);
		if (*format == '%')
			count = count + check_format(*(++format), args);
		else
			count = count + write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
int main ()
{
	ft_printf("%%%m");
}
