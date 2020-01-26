/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:24:00 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/12 15:16:26 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/wolf3d.h"

void	display_column(t_env *e)
{
	float	i;
	int	top_wall;
	int	column_size;

	column_size = calc_column(e);
	top_wall = (e->winy/2)-(column_size/2);
	i = 0;
	while (i <= column_size)
	{
		e->pixel.x = 50;
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, 255, e);
		top_wall++;
		i++;
	}
}
