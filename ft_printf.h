/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:57:03 by obouftou          #+#    #+#             */
/*   Updated: 2024/11/25 12:46:05 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_puthexa_printf(unsigned int n, const char f);
int	ft_putadress_printf(void *ptr);
int	ft_putchar_printf(char c);
int	ft_putnbr_printf(int nb);
int	ft_putstr_printf(char *str);
int	ft_unsigned_printf(unsigned int nb);
int	ft_printf(const char *format, ...);

#endif
