/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:24:00 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/12 12:30:02 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/wolf3d.h"

void	display_wall(t_env *e, int column_size, int top_wall)
{
	int i;
	int c;

	c = 0;
	i = 1276 * top_wall;
	while (c <= 319)
	{
		while (column_size <= 0)
		{
			e->img_string[i] = 255;
			e->img_string[i + 1] = 255;
			e->img_string[i + 2] = 255;
			e->img_string[i + 3] = 255;
		}
		c++;
	}
}
