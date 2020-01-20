/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:47:38 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/20 15:06:04 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	print_texture(t_env *e, t_point pixel, t_point texel)
{
	int	pos;
	int texel_pos;

	pos = pixel.y * e->winx * 4 + pixel.x * 4;
	texel_pos = texel.x * 64 * 4 + texel.y * 4;
	e->img_string[pos] = e->tex.east_img[texel_pos];
	e->img_string[pos + 1] = e->tex.east_img[texel_pos + 1];
	e->img_string[pos + 2] = e->tex.east_img[texel_pos + 2];
}

void	calc_ray_posx(t_env *e)
{
	double wallx;

	wallx = e->player.y + (e->rayang - e->rot) * e->disty; 
}
