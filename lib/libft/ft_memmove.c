/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:12:58 by akaratas          #+#    #+#             */
/*   Updated: 2023/11/02 18:55:09 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (src < dst)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[(len - 1)] = ((unsigned char *)src)[(len
					- 1)];
			len--;
		}
	}
	return (dst);
}
