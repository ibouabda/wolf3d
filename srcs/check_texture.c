/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/27 15:16:25 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	load_texture(t_txt *t, t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	if ((t->ptr_image = mlx_xpm_file_to_image(e->mlx_ptr, t->image, &t->width, &t->height)) == NULL)
		ft_exit(1, NULL, e);
	ft_strdel(&t->image);
	t->image =  mlx_get_data_addr(t->ptr_image, &(bpp), &(s_l), &(endian));
}

void	open_texture(t_env *e)
{	
	load_texture(&e->images.north, e);
	load_texture(&e->images.east, e);
	load_texture(&e->images.west, e);
	load_texture(&e->images.south, e);
	if (e->images.north.height != e->images.east.height
	|| e->images.north.height != e->images.west.height
	|| e->images.north.height != e->images.south.height
	|| e->images.north.width != e->images.east.width
	|| e->images.north.width != e->images.west.width
	|| e->images.north.width != e->images.south.width)
		ft_exit(1, NULL, e);
}
