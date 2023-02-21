/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:05:14 by arebelo           #+#    #+#             */
/*   Updated: 2022/05/16 16:50:11 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libc.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define TILE_WIDTH 32
# define TILE_HEIGHT 32

# define MOVE_ENEM 8000
# define CHANGE_ENEM 1000

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0

# define FIRE_UP 8
# define FIRE_DOWN 9

typedef struct s_stru
{
	size_t	memory;
	size_t	cols;
	size_t	rows;
	size_t	exit;
	size_t	collectible;
	size_t	sp;
}	t_stru;

typedef struct s_img
{
	void	*img_ptr;
	int		*img_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img_stock;
	char	*nl;
	t_stru	*mem;
	size_t	moves;
	int		pid;
	_Bool	game_stat;
	_Bool	imgs_created;
	_Bool	enemy;
	int		count;
}	t_vars;

char			*get_next_line(int fd);
void			ft_putstr(char *str);
char			*ft_strndup(char *s1, size_t n);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_2(char *s1, char *s2);
char			*first_line(int fd, char buf[1], int *i);
char			*following_lines(int fd, char buf[1], int *i);
unsigned long	counter(char *buf, int j);

_Bool			line_one(char *nl, t_stru *mem);
_Bool			line_last(char *nl, t_stru *mem);
_Bool			line_middle(char *nl, t_stru *mem);
_Bool			fill_array(char *argv, char **nl, t_stru *mem);

_Bool			img_background(t_vars *vars);
_Bool			img_wall(t_vars *vars);
_Bool			img_collectible(t_vars *vars);
_Bool			img_exit(t_vars *vars);
_Bool			img_player_right(t_vars *vars);
_Bool			img_player_left(t_vars *vars);
_Bool			img_player_up(t_vars *vars);
_Bool			img_player_down(t_vars *vars);
_Bool			img_fire_up(t_vars *vars);
_Bool			img_fire_down(t_vars *vars);

_Bool			print_initial_img(t_vars *vars, t_stru mem);
_Bool			init_imgs(t_vars *vars);

int				key_hook(int keycode, t_vars *vars);
int				red_cross(t_vars *vars);
int				exit_hook(int keycode, t_vars *vars);
int				inactive(t_vars *vars);
void			exit_clean(t_vars *vars);

void			keycode_up(t_vars *vars, int *x, int *y, int *pos);
void			keycode_down(t_vars *vars, int *x, int *y, int *pos);
void			keycode_right(t_vars *vars, int *x, int *y, int *pos);
void			keycode_left(t_vars *vars, int *x, int *y, int *pos);
void			move_x(t_vars *vars, int pos);

void			up_keycode(t_vars *vars, int *x, int *y);
void			down_keycode(t_vars *vars, int *x, int *y);
void			right_keycode(t_vars *vars, int *x, int *y);
void			left_keycode(t_vars *vars, int *x, int *y);

int				find_k(t_vars *vars, int pos);
int				find_piece(char piece, char c, t_vars *vars);
int				create_trgb(int t, int r, int g, int b);
void			move_player(t_vars *vars, int x, int y, int pos);
void			put_background(t_vars *vars, int x, int y);

int				is_exit(t_vars *vars, int x, int y);
void			terminate_game(t_vars *vars, int trgb, char *str);
void			eval_finish(t_vars *vars, int x, int y);

void			animate_enemy(t_vars *vars);

#endif
