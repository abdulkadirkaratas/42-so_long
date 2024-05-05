/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:28:44 by akaratas          #+#    #+#             */
/*   Updated: 2023/12/10 19:40:06 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}

int	ft_cspdiux(char c, va_list ap, int *index)
{
	int	arg_len;

	arg_len = 0;
	if (c == 'c')
		arg_len = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		arg_len = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		arg_len = ft_hexadress(va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		arg_len = ft_putnbr_signed(va_arg(ap, int));
	else if (c == 'u')
		arg_len = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		arg_len = ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		arg_len = ft_putchar('%');
	else
		index[0] = index[0] - 1;
	return (arg_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		arg_len;
	va_list	ap;

	va_start(ap, str);
	arg_len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			arg_len = arg_len + ft_cspdiux(str[i], ap, &i);
		}
		else
			arg_len = arg_len + ft_putchar(str[i]);
		i++;
	}
	return (arg_len);
}
