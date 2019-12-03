/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/03 11:18:47 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/wolf3d.h"

void	open_texture(t_env *e)
{
	if(!open(e->north_texture, O_RDONLY))
		ft_exit_params(e);
	if(!open(e->south_texture, O_RDONLY))
		ft_exit_params(e);
	if(!open(e->east_texture, O_RDONLY))
		ft_exit_params(e);
	if(!open(e->west_texture, O_RDONLY))
		ft_exit_params(e);
	if(!open(e->sprite_texture, O_RDONLY))
		ft_exit_params(e);
}
