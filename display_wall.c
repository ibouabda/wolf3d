/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:24:00 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/12 12:34:34 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/wolf3d.h"

void	display_wall(t_env *e, int column_size, int top_wall)
{
	int i;
	int c;

	c = 0;
	i = column_size;
	while (c <= 319)
	{
		while (i <= column_size)
		{
			ft_fill_pixel();
		}
		c++;
	}
}
