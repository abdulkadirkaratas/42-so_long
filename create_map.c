/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:01:30 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/04 16:56:30 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	strlen_without_newline(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0' && s[size] != '\n')
		size++;
	return (size);
}

static void	find_map_height(t_game *game_p, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error("Check to map path!", game_p);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(game_p->map_height)++;
		free(line);
	}
	close(fd);
}

static void	fill_map(t_game *game_p, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < game_p->map_height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(game_p->map)[i] = ft_substr(line, 0, strlen_without_newline(line));
		if (i == ((game_p->map_height) - 1))
		{
			if (line[ft_strlen(line) - 1] == '\n')
			{
				free(line);
				error("Map file last line is empty.", game_p);
			}
		}
		free(line);
		i++;
	}
}

void	create_map(t_game *game_p, char *file_path)
{
	int		fd;

	ber_file_check(file_path, game_p);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error("Check to map path!", game_p);
	find_map_height(game_p, file_path);
	game_p->map = (char **)malloc(((game_p->map_height) + 1) * sizeof(char *));
	if (game_p->map == NULL)
		error("game_p->map cannot be allocated.", game_p);
	(game_p->map)[game_p->map_height] = NULL;
	fill_map(game_p, fd);
	close(fd);
}
