/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:29:14 by akaratas          #+#    #+#             */
/*   Updated: 2024/04/24 19:13:41 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_signed(int n)
{
	char	*num_str;
	int		num_len;

	num_str = ft_itoa_signed(n, "0123456789");
	num_len = ft_strlen(num_str);
	ft_putstr(num_str);
	free(num_str);
	return (num_len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	*num_str;
	int		num_len;

	num_str = ft_itoa_unsigned(n, "0123456789");
	num_len = ft_strlen(num_str);
	ft_putstr(num_str);
	free(num_str);
	return (num_len);
}

int	ft_hexadress(unsigned long n)
{
	char	*hex_str;
	int		hex_len;

	hex_str = ft_itoa_unsigned(n, "0123456789abcdef");
	hex_len = ft_strlen(hex_str);
	ft_putstr("0x");
	ft_putstr(hex_str);
	free(hex_str);
	return (hex_len + 2);
}

int	ft_puthex(unsigned int n, char c)
{
	char	*base;
	char	*hex_str;
	int		hex_len;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	hex_str = ft_itoa_unsigned(n, base);
	hex_len = ft_strlen(hex_str);
	ft_putstr(hex_str);
	free(hex_str);
	return (hex_len);
}
