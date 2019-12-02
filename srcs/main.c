/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/02 11:48:05 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_exit(int err, char **dbtable, t_list *m)
{
	if (dbtable)
		ft_2dmemdel((void**)dbtable);
	if (m)
		ft_lstdelstr(m);
	if (err == 1)
		ft_putendl("error");
	while (1);
	exit(err);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		ft_exit(1, NULL, NULL);
	checkandparse(argv[1], &e);
	ft_2dputstr(e.dbtab);
	ft_putnbrl(e.mapx);
	ft_putnbrl(e.mapy);
	while (1);
	return (0);
}
