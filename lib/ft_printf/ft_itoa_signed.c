/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:30:01 by akaratas          #+#    #+#             */
/*   Updated: 2023/12/10 17:36:36 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_counter(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = (n / 10);
		count++;
	}
	return (count);
}

static void	ft_convert_string(char *str, long num, int num_len, char *base)
{
	if (num == 0)
		str[0] = '0';
	else if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[num_len - 1] = base[num % 10];
		num = (num / 10);
		num_len--;
	}
}

char	*ft_itoa_signed(long num, char *base)
{
	int		num_len;
	char	*str;

	num_len = ft_digit_counter(num);
	str = (char *)malloc(num_len + 1);
	if (str == 0)
		return (0);
	ft_convert_string(str, num, num_len, base);
	str[num_len] = '\0';
	return (str);
}
