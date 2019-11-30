/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:45:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/11/30 13:50:40 by ibouabda         ###   ########.fr       */
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

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

# define TITLE "WOLF_3D"
# define BEGIN "Let's Play : Press On ENTER"
# define MOVE "Move : Arrows"
# define VAR "Activate/Desactivate Variation : Right Click"
# define ZOOM "Zoom/Unzoom : Scroll"
# define COLORS "Choose Colors : R, G, B, N"
# define FRACTAL "Choose Fractal : 1, 2, 3, 4"
# define PAUSE "Pause : ESC"
# define RESET "Reset : Z"
# define QUIT "If You Wanna Quit The Game Press On ESC"

# include "../libft/incl/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_env
{
	int				bool;
	int				depx;
	int				depy;
	int				winx;
	int				winy;
	int				midx;
	int				midy;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*esc_img_ptr;
	void			*img_ptr;
	char			*img_string;
}				t_env;

#endif
