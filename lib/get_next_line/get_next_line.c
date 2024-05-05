/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:21:47 by akaratas          #+#    #+#             */
/*   Updated: 2024/04/26 17:37:09 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_line_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_and_join(int fd, char *buffer_set)
{
	char	*buffer_reader;
	int		read_len;

	buffer_reader = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer_reader)
		return (NULL);
	read_len = read(fd, buffer_reader, BUFFER_SIZE);
	if (read_len == -1)
		return (free(buffer_set), free(buffer_reader), NULL);
	while (read_len > 0)
	{
		buffer_reader[read_len] = '\0';
		buffer_set = gnl_strjoin(buffer_set, buffer_reader);
		if (next_line_index(buffer_set) != -1)
			break ;
		read_len = read(fd, buffer_reader, BUFFER_SIZE);
	}
	free(buffer_reader);
	return (buffer_set);
}

char	*single_line(char *buffer_set)
{
	char	*line;
	int		line_len;

	line_len = next_line_index(buffer_set);
	if (line_len == -1)
		line_len = gnl_strlen(buffer_set);
	else
		line_len = line_len + 1;
	line = gnl_substr(buffer_set, 0, line_len);
	return (line);
}

char	*update_buffer_set(char *buffer_set)
{
	char	*new_buffer_set;
	int		nl_index;
	int		new_len;

	nl_index = next_line_index(buffer_set);
	if (nl_index == -1)
	{
		free(buffer_set);
		return (NULL);
	}
	new_len = gnl_strlen(buffer_set) - (nl_index + 1);
	new_buffer_set = gnl_substr(buffer_set, (nl_index + 1), new_len);
	free(buffer_set);
	return (new_buffer_set);
}

char	*get_next_line(int fd)
{
	static char	*buffer_set;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_set = read_and_join(fd, buffer_set);
	if (buffer_set == NULL)
		return (NULL);
	line = single_line(buffer_set);
	buffer_set = update_buffer_set(buffer_set);
	return (line);
}
