/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2020/02/03 15:17:28 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

int		calc_column(t_env *e, int *top_wall, int ray_num, int i)
{
	int		column_size;
	float	ray_dist_fisheyed;

	ray_dist_fisheyed = e->ray_dist * cos((e->rayang - e->rot) / e->pi);
	column_size = (64 / ray_dist_fisheyed) * e->project_screen;
	*top_wall = e->midy - (column_size / 2);
	if (*top_wall < 0 || *top_wall > e->winy)
		*top_wall = 0;
	if (e->wall_dir == 'h')
		e->texel.x = ((int)(((e->ddax.x)
		- (int)(e->ddax.x)) * e->images.north.width)) * 4;
	else
		e->texel.x = ((int)(((e->ddax.y)
		- (int)(e->ddax.y)) * e->images.north.height)) * 4;
	e->pixel.x = ray_num * 4;
	while (i <= e->winy && i < *top_wall)
	{
		e->pixel.y = i;
		ft_fill_pixel(e->pixel, e->images.ceiling_color, e);
		i++;
	}
	return (column_size);
}

void	display_column(t_env *e, int ray_num, int i, int column_size)
{
	int		column_dif;
	int		top_wall;
	float	texel_prop;

	column_size = calc_column(e, &top_wall, ray_num, 0);
	i = column_size > e->winy ? (column_size - e->winy) / 2 : 0;
	column_dif = i;
	texel_prop = column_size / (float)e->images.north.height;
	while ((i < e->winy && i < column_size)
	|| (column_size > e->winy && i < e->winy + column_dif))
	{
		e->texel.y = i / texel_prop;
		e->pixel.y = top_wall;
		display_texture(e);
		top_wall++;
		i++;
	}
	while (top_wall < e->winy)
	{
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, e->images.floor_color, e);
		top_wall++;
	}
}
