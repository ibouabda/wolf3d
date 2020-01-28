/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/28 11:40:16 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

int		calc_column(t_env *e, int *top_wall, int ray_num, int i)
{
	double	column_size;
	double	ray_dist_fisheyed;

	ray_dist_fisheyed = ABS(e->ray_dist * cos((e->rayang - e->rot) / e->pi));
	column_size = (64 / ray_dist_fisheyed) * e->dist;
	*top_wall = e->mid_winy - (column_size / 2);
	if (*top_wall < 0 || *top_wall > e->winy)
		*top_wall = 0;
	if (e->wall_dir == 'h')
		e->texel.x = ((int)(((e->player.x + e->dday.x)
		- (int)(e->dday.x + e->player.x)) * e->images.north.width));
	else
		e->texel.x = ((int)(((e->player.y + e->ddax.y)
		- (int)(e->ddax.y + e->player.y)) * e->images.north.height));
	while (i < e->winy && i < *top_wall)
	{
		e->pixel.x = ray_num;
		e->pixel.y = i;
		ft_fill_pixel(e->pixel, e->images.ceiling_color, e);
		i++;
	}
	return (column_size);
}

void	display_column(t_env *e, int ray_num)
{
	int		i;
	int		column_size;
	int		column_dif;
	int		top_wall;

	column_size = calc_column(e, &top_wall, ray_num, 0);
	i = column_size > e->winy ? (column_size - e->winy) / 2 : 0;
	column_dif = i;
	while ((i < e->winy && i < column_size)
	|| (column_size > e->winy && i < e->winy + column_dif))
	{
		e->texel.y = i / (column_size / (double)e->images.north.height);
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		display_texture(e);
		top_wall++;
		i++;
	}
	while (top_wall < e->winy)
	{
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, e->images.floor_color, e);
		top_wall++;
	}
}
