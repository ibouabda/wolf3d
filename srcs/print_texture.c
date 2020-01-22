/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:47:38 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/22 14:55:57 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	print_texture(t_env *e, t_point pixel, t_point texel)
{
	int	pos;
	int texel_pos;

	pos = pixel.y * e->winx * 4 + pixel.x * 4;
	texel_pos = texel.x * 64 * 4 + texel.y * 4;
	if (e->ray_dist <= 150.0)
	{
		// printf("ray_dist : %f\n", e->ray_dist);
		e->img_string[pos] = e->tex.east_tex[texel_pos] - (e->ray_dist / 3.0);
		e->img_string[pos + 1] = e->tex.east_tex[texel_pos + 1] - (e->ray_dist / 3.0);
		e->img_string[pos + 2] = e->tex.east_tex[texel_pos + 2] - (e->ray_dist / 3.0);
	}
	else
	{
		e->img_string[pos] = e->tex.east_tex[texel_pos] - 150 / 3;
		e->img_string[pos + 1] = e->tex.east_tex[texel_pos + 1] - 150 / 3;
		e->img_string[pos + 2] = e->tex.east_tex[texel_pos + 2] - 150 / 3;
	}
}

void	calc_ray_posx(t_env *e)
{
	double	wallx;
	int		texnum;

	texnum = e->dbtab[e->mapx][e->mapy] - 1;
	wallx = e->player.y + (e->rayang - e->rot) * e->disty; 
}
