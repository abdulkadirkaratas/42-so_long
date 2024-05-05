/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:27:06 by akaratas          #+#    #+#             */
/*   Updated: 2023/10/30 19:15:27 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_counter(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_convert_string(char *str, long num, int num_len)
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
		str[num_len - 1] = (num % 10) + 48;
		num = num / 10;
		num_len--;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		num_len;
	char	*str;

	num = n;
	num_len = ft_digit_counter(num);
	str = (char *)malloc(num_len + 1);
	if (str == 0)
		return (0);
	ft_convert_string(str, num, num_len);
	str[num_len] = '\0';
	return (str);
}
