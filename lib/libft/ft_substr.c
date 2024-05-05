/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:03:28 by akaratas          #+#    #+#             */
/*   Updated: 2023/11/02 19:02:54 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == 0)
		return (0);
	if ((start >= ft_strlen(s)))
		return (ft_strdup("\0"));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	substr = (char *)malloc(len + 1);
	if (substr == 0)
		return (0);
	ft_memcpy(substr, &(s[start]), len);
	substr[len] = '\0';
	return (substr);
}
