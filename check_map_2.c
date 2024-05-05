/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:53:14 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/04 17:42:05 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		exit(0);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error(char *error_message, t_game *game_p)
{
	ft_printf("%s\n", error_message);
	free_map(game_p->map);
	exit(0);
}

static void	flood_fill_algorithm(int x, int y, char **map, t_game *game_p)
{
	if (x < 0 || x > game_p->map_width - 1 || y < 0 || y > game_p->map_height
		- 1)
		return ;
	if (map[y][x] != '1' && map[y][x] != 'F')
	{
		map[y][x] = 'F';
		flood_fill_algorithm(x, (y - 1), map, game_p);
		flood_fill_algorithm(x, (y + 1), map, game_p);
		flood_fill_algorithm((x - 1), y, map, game_p);
		flood_fill_algorithm((x + 1), y, map, game_p);
	}
}

void	map_valid_path_check_2(t_game *game_p, char **map_copy)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < game_p->map_height)
	{
		line = map_copy[i];
		j = 0;
		while (j < game_p->map_width)
		{
			if (line[j] == ITEM || line[j] == EXIT)
			{
				free_map(map_copy);
				error("All Collectible and Exit must be accessible.", game_p);
			}
			j++;
		}
		i++;
	}
}

void	map_valid_path_check(t_game *game_p)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(((game_p->map_height) + 1) * sizeof(char *));
	if (map_copy == NULL)
		error("map_copy cannot be allocated.", game_p);
	i = 0;
	while (i < game_p->map_height)
	{
		map_copy[i] = ft_strdup((game_p->map)[i]);
		i++;
	}
	map_copy[i] = NULL;
	flood_fill_algorithm((game_p->player_coordinate).x,
		(game_p->player_coordinate).y, map_copy, game_p);
	map_valid_path_check_2(game_p, map_copy);
	free_map(map_copy);
}
