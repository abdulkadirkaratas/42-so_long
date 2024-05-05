/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:05:48 by akaratas          #+#    #+#             */
/*   Updated: 2024/04/24 19:44:04 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*gnl_strdup(const char *s1)
{
	size_t	s1_len;
	char	*new_str;

	s1_len = gnl_strlen(s1);
	new_str = (char *)malloc((s1_len + 1));
	if (new_str == 0)
		return (0);
	gnl_memcpy(new_str, s1, (s1_len + 1));
	return (new_str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*newstr;

	if (!s1)
		s1 = gnl_strdup("");
	if (!s1 || !s2)
		return (0);
	total_len = gnl_strlen(s1) + gnl_strlen(s2);
	newstr = (char *)malloc(total_len + 1);
	if (newstr == 0)
		return (0);
	gnl_memcpy(newstr, s1, gnl_strlen(s1));
	gnl_memcpy(&(newstr[gnl_strlen(s1)]), s2, gnl_strlen(s2));
	newstr[total_len] = '\0';
	free(s1);
	return (newstr);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == 0)
		return (0);
	if ((start >= gnl_strlen(s)))
		return (NULL);
	if (len > (gnl_strlen(s) - start))
		len = (gnl_strlen(s) - start);
	substr = (char *)malloc(len + 1);
	if (substr == 0)
		return (0);
	gnl_memcpy(substr, &(s[start]), len);
	substr[len] = '\0';
	return (substr);
}
