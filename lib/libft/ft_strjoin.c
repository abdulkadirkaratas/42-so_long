/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:25:51 by akaratas          #+#    #+#             */
/*   Updated: 2023/10/30 19:12:26 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(total_len + 1);
	if (newstr == 0)
		return (0);
	ft_memcpy(newstr, s1, ft_strlen(s1));
	ft_memcpy(&(newstr[ft_strlen(s1)]), s2, ft_strlen(s2));
	newstr[total_len] = '\0';
	return (newstr);
}
