/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/04 13:56:31 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	open_texture(t_env *e)
{
	int width;
	int height;
	if ((e->tex.north_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.north_tex, &width, &height)) == NULL)
	{
		printf("a\n");
		ft_exit(1, NULL, e);
	}
	else
		mlx_put_image_to_window(e->tex.north_img, e->win_ptr, e->img_ptr, e->winx, e->winy);
}
