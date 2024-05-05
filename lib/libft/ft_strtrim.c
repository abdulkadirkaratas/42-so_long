/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42ist.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:21 by akaratas          #+#    #+#             */
/*   Updated: 2023/10/30 19:15:17 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first_index;
	int	last_index;

	if (!s1 || !set)
		return (0);
	first_index = 0;
	while (s1[first_index] != '\0')
	{
		if (ft_strchr(set, s1[first_index]) == 0)
			break ;
		first_index++;
	}
	last_index = ft_strlen(s1) - 1;
	while (last_index >= 0)
	{
		if (ft_strchr(set, s1[last_index]) == 0)
			break ;
		last_index--;
	}
	return (ft_substr(s1, first_index, (last_index - first_index + 1)));
}
