/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:32:16 by akaratas          #+#    #+#             */
/*   Updated: 2023/12/10 17:40:46 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_counter(unsigned long n, int base_len)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = (n / base_len);
		count++;
	}
	return (count);
}

static void	ft_convert_string(char *str, unsigned long num, int num_len,
		char *base)
{
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[num_len - 1] = base[num % ft_strlen(base)];
		num = (num / ft_strlen(base));
		num_len--;
	}
}

char	*ft_itoa_unsigned(unsigned long num, char *base)
{
	int		num_len;
	char	*str;

	num_len = ft_digit_counter(num, ft_strlen(base));
	str = (char *)malloc(num_len + 1);
	if (str == 0)
		return (0);
	ft_convert_string(str, num, num_len, base);
	str[num_len] = '\0';
	return (str);
}
