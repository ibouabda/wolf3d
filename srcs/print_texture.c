/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:47:38 by retounsi          #+#    #+#             */
/*   Updated: 2020/02/01 11:46:40 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

static void	print_texture(t_env *e, t_txt *txt, int pos, int texel_pos)
{
	e->img_string[pos] = txt->image[texel_pos];
	e->img_string[pos + 1] = txt->image[texel_pos + 1];
	e->img_string[pos + 2] = txt->image[texel_pos + 2];
}

void		display_texture(t_env *e)
{
	int	pos;
	int texel_pos;

	pos = e->pixel.y * e->winx_img + e->pixel.x;
	texel_pos = e->texel.y * e->texture_res_img + e->texel.x;
	if (e->wall_dir == 'h' && e->rayang >= 0 && e->rayang <= 180)
		print_texture(e, &e->images.north, pos, texel_pos);
	else if (e->wall_dir == 'h' && e->rayang <= 360 && e->rayang >= 180)
		print_texture(e, &e->images.south, pos, texel_pos);
	else if (e->wall_dir == 'v' && e->rayang >= 90 && e->rayang <= 270)
		print_texture(e, &e->images.west, pos, texel_pos);
	else if ((e->rayang <= 90 && e->rayang >= 0)
		|| (e->rayang >= 270 && e->rayang <= 360))
		print_texture(e, &e->images.east, pos, texel_pos);
}
