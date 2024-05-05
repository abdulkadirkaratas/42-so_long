/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:15:03 by akaratas          #+#    #+#             */
/*   Updated: 2023/11/02 19:01:14 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while ((i < len) && (haystack[i] != '\0'))
	{
		if ((ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0) && ((i
					+ ft_strlen(needle)) <= len))
			return (&((char *)haystack)[i]);
		i++;
	}
	return (0);
}
