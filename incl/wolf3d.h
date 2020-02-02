/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:45:07 by ibouabda          #+#    #+#             */
/*   Updated: 2020/02/02 17:46:51 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

# define WOLF3D_H
# define ESC 53

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 5
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6
# define MINUS 27
# define PLUS 24
# define ENTER 36

# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21

# define ONE_NUM_PAD 83
# define TWO_NUM_PAD 84
# define THREE_NUM_PAD 85
# define FOUR_NUM_PAD 86
# define FIVE_NUM_PAD 87
# define SIX_NUM_PAD 88
# define SEVEN_NUM_PAD 89
# define EIGHT_NUM_PAD 91
# define NINE_NUM_PAD 92

# define LESS 78
# define MORE 69

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

# define MOTION_NOTIFY 6
# define KEY_PRESS 2

# define TITLE "WOLF_3D"
# define BEGIN "Let's Play : Press On ENTER"
# define MOVE "Move Forward & Backward : UP & Down Arrow Or W & S"
# define STRAF "Straf : A & D"
# define ROTATE "Rotation : LEFT_ARROW & RIGHT_ARROW"
# define PAUSE "Pause : ESC"
# define QUIT "Press ESC Or Click on the Cross To Quit The Game"

# include "../libft/incl/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_txt
{
	void	*ptr_image;
	char	*image;
	int		width;
	int		height;
}				t_txt;

typedef struct	s_images
{
	t_txt	north;
	t_txt	south;
	t_txt	west;
	t_txt	east;
	t_txt	sprite;
	int		*floor_color;
	int		*ceiling_color;
	int		*wall_color;
}				t_images;

typedef struct	s_env
{
	t_fpoint		wallx;
	t_fpoint		wally;
	int				wall_dir;
	float			raylag;
	float			rayang;
	int				mid_wall;
	t_fpoint		ddax;
	t_fpoint		dday;
	int				bool;
	t_images		images;
	t_fpoint		player;
	float			pi;
	int				mapx;
	int				mapy;
	t_point			pixel;
	t_point			texel;
	float			texel_prop;
	int				winx;
	int				winx_img;
	int				texture_res_img;
	int				winy;
	int				midy;
	int				project_screen;
	float			ang;
	int				rot;
	char			**dbtab;
	float			ray_dist;
	float			var;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*esc_img_ptr;
	void			*img_ptr;
	char			*img_string;
}				t_env;

void			checkandparse(char *argv, t_env *e);
int				ft_check_line(t_list *m);
void			read_res(char *line, t_env *e, int i);
void			read_path(char *line, t_env *e, int i, char **str);
void			read_colors(char *line, t_env *e, int i, int **tab);
int				read_first_param(int fd, t_env *e, t_images *images);
void			ft_exit(int err, t_list *m, t_env *e);
void			new_window(t_env *e);
void			img(t_env *e);
void			new_img(t_env *e);
void			open_texture(t_env *e);
int				key_hook(int keycode, t_env *e);
void			display_wall(t_env *e, float wall_size, float wall_top);
void			ft_fill_pixel(t_point point, int *color, t_env *e);
void			img(t_env *e);
float			ft_dda(t_env *e);
void			ft_line2(t_env *e, float m);
void			vertical(t_env *e);
void			vertical2(t_env *e);
int				ft_distline(t_env *e);
void			ray_dist(t_env *e);
void			display_column(t_env *e, int ray_num, int i, int column_size);
float			fish_eye_calc_dist(t_env *e);
void			display_texture(t_env *e);
void			print_sprite(t_env *e, t_point point, t_point sprite_cord);
void			interface(t_env *e);

#endif
