/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:17:57 by akaratas          #+#    #+#             */
/*   Updated: 2023/11/02 18:56:58 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	new_str = (char *)malloc((s1_len + 1));
	if (new_str == 0)
		return (0);
	ft_memcpy(new_str, s1, (s1_len + 1));
	return (new_str);
}
