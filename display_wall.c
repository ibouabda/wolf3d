/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:24:00 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/10 16:43:09 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/wolf3d.h"

int		wall_top(t_env *e)
{

}

void	display_wall(t_env *e)
{
	int		wall_size;
	int		wall_top;

	wall_size = fish_eye_calc_dist(e);
	wall_top = (project_sreen\2)-(wall_size/2);
	while (e->img_string && )
}
