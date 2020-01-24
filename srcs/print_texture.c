/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:47:38 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/24 12:13:36 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	print_east_west_text(t_env *e, int pos, int texel_pos)
{
	if (e->wall_dir == 'v' && e->rayang >= 90 && e->rayang <= 270)
	{
		e->img_string[pos] = e->tex.west_tex[texel_pos];
		e->img_string[pos + 1] = e->tex.west_tex[texel_pos + 1];
		e->img_string[pos + 2] = e->tex.west_tex[texel_pos + 2];
	}
	else if ((e->rayang <= 90 && e->rayang >= 0)
	|| (e->rayang >= 270 && e->rayang <= 360))
	{
		e->img_string[pos] = e->tex.east_tex[texel_pos];
		e->img_string[pos + 1] = e->tex.east_tex[texel_pos + 1];
		e->img_string[pos + 2] = e->tex.east_tex[texel_pos + 2];
	}
}

void	print_texture(t_env *e, t_point pixel, t_point texel)
{
	int	pos;
	int texel_pos;

	pos = pixel.y * e->winx * 4 + pixel.x * 4;
	texel_pos = texel.x * 64 * 4 + texel.y * 4;
	if (e->wall_dir == 'h' && e->rayang >= 0 && e->rayang <= 180)
	{
		e->img_string[pos] = e->tex.north_tex[texel_pos];
		e->img_string[pos + 1] = e->tex.north_tex[texel_pos + 1];
		e->img_string[pos + 2] = e->tex.north_tex[texel_pos + 2];
	}
	else if (e->wall_dir == 'h' && e->rayang <= 360 && e->rayang >= 180)
	{
		e->img_string[pos] = e->tex.south_tex[texel_pos];
		e->img_string[pos + 1] = e->tex.south_tex[texel_pos + 1];
		e->img_string[pos + 2] = e->tex.south_tex[texel_pos + 2];
	}
	else
		print_east_west_text(e, pos, texel_pos);
}

// void	print_texture(t_env *e, t_point pixel, t_point texel)
// {
// 	int	pos;
// 	int texel_pos;

// 	pos = pixel.y * e->winx * 4 + pixel.x * 4;
// 	texel_pos = texel.x * 64 * 4 + texel.y * 4;
// 	if (e->ray_dist <= 150.0)
// 	{
// 		// printf("ray_dist : %f\n", e->ray_dist);
// 		e->img_string[pos] = e->tex.east_tex[texel_pos] - (e->ray_dist / 3.0);
// 		e->img_string[pos + 1] = e->tex.east_tex[texel_pos + 1] - (e->ray_dist / 3.0);
// 		e->img_string[pos + 2] = e->tex.east_tex[texel_pos + 2] - (e->ray_dist / 3.0);
// 	}
// 	else
// 	{
// 		e->img_string[pos] = e->tex.east_tex[texel_pos] - 150 / 3;
// 		e->img_string[pos + 1] = e->tex.east_tex[texel_pos + 1] - 150 / 3;
// 		e->img_string[pos + 2] = e->tex.east_tex[texel_pos + 2] - 150 / 3;
// 	}
// }

void	print_sprite(t_env *e, t_point point, t_point sprite_cord)
{
	int	pos;
	int sprite_pos;

	pos = point.y * e->winx * 4 + point.x * 4;
	sprite_pos = sprite_cord.y * e->winx * 32 + sprite_cord.x * 4;
	if (e->tex.sprite_tex[sprite_pos + 3] != 0)
	{
		e->img_string[pos] = e->tex.sprite_tex[sprite_pos];
		e->img_string[pos + 1] = e->tex.sprite_tex[sprite_pos + 1];
		e->img_string[pos + 2] = e->tex.sprite_tex[sprite_pos + 2];
	}
}
