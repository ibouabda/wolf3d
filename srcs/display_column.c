/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/24 11:03:03 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

// void	calc_sprite(t_env *e, void *dist_sprite, int ray_num)
// {
// 	t_point sprite_cord;
// 	int		top_sprite;
// 	int		sprite_size;
// 	int		i;

// 	i = 0;
// 	sprite_size = 32 * (dist_sprite / 277);
// 	top_sprite = (e->winy / 2) + (sprite_size / 2);
// 	sprite_cord.x = ((int)(((e->player.x + e->distx) - (int)(e->distx + e->player.x)) * 32));
// 	while (i < sprite_size)
// 	{
// 		e->pixel.x = ray_num;
// 		e->pixel.y = top_sprite;
// 		print_sprite(e, e->pixel, sprite_cord);
// 		sprite_cord.y = i / (sprite_size / 32);
// 		top_sprite++;
// 		i++;
// 	}
// }

// void	display_sprite(t_env *e, t_list *sprite, int ray_num)
// {
// 	while (sprite)
// 	{
// 		calc_sprite(e, sprite->content, ray_num);
// 		sprite = sprite->next;
// 	}
// }

double	fish_eye_calc_dist(t_env *e)
{
	double	real_dist_ray;

	real_dist_ray = ABS(e->ray_dist  * cos((e->rayang - e->rot) / e->pi));
	// printf("ray_ang : %f\n", e->rayang);
	// printf("ray_ang - e->rot : %f\n", e->rayang - e->rot);
	// printf("ray_dist : %f\n", e->ray_dist);
	// printf("cos : %f\n", cos);
	// printf("real_ray : %f\n", real_dist_ray);
	// printf("ray_dist * cos : %f\n", (double)((double)e->ray_dist * (double)cos));
	return (real_dist_ray);
}

int		calc_column(t_env *e)
{
	double	column_size;
	double	ray_dist_fisheyed;
	double	top_wall;

	ray_dist_fisheyed = fish_eye_calc_dist(e);
	column_size = (64 / ray_dist_fisheyed) * 519;
	return(column_size);
}

void	display_column(t_env *e, int ray_num)
{
	int		i;
	int		top_wall;
	int		column_size;
	int		column_dif;

	column_dif = (column_size - e->winy) / 2;
	column_size = calc_column(e);
	top_wall = (e->winy / 2) - (column_size / 2);
	if (top_wall < 0 || top_wall > e->winy)
		top_wall = 0;
	i = 0;
	if (e->wall_dir == 'h')
		e->texel.x = ((int)(((e->player.x + e->dday.x) - (int)(e->dday.x + e->player.x)) * 64));
	else
		e->texel.x = ((int)(((e->player.x + e->ddax.x) - (int)(e->ddax.x + e->player.x)) * 64));
	while (i < e->winy && i < top_wall)
	{
		e->pixel.x = ray_num;
		e->pixel.y = i;
		ft_fill_pixel(e->pixel, e->tex.ceiling_color, e);
		i++;
	}
	i = column_size > e->winy ? (column_size - e->winy) / 2 : 0;
	column_dif = i;
	while ((i < e->winy && i < column_size)
	|| (column_size > e->winy && i < e->winy + column_dif))
	{
		e->texel.y = i / (column_size / 64.0);
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		print_texture(e, e->pixel, e->texel);
		top_wall++;
		i++;
	}
	while (top_wall < e->winy)
	{
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, e->tex.floor_color, e);
		top_wall++;
	}
}
