/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:53:33 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/04 18:42:55 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define EXIT_BUTTON_EVENT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_counter
{
	int			player;
	int			item;
	int			exit;
}				t_counter;

typedef struct s_img
{
	void		*floor;
	void		*wall;
	void		*player;
	void		*item;
	void		*exit;
}				t_img;

typedef struct s_game
{
	char		**map;
	int			map_height;
	int			map_width;
	t_player	player_coordinate;
	t_exit		exit_coordinate;
	t_counter	counter;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img_ptr;
}				t_game;

void			create_map(t_game *game, char *file_path);
void			error(char *error_message, t_game *game_p);
void			free_map(char **map);

void			ber_file_check(char *file_path, t_game *game_p);
void			map_format_check(t_game *game);
void			map_valid_path_check(t_game *game_p);

void			create_mlx_window(t_game *game);
void			put_image_to_window(t_game *game_p);

int				key_handler(int keycode, t_game *game_p);
int				close_handler(t_game *game_p);

#endif
