/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:36:51 by idris             #+#    #+#             */
/*   Updated: 2020/01/21 17:36:10 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"


void ddax(t_env *e, double ystep)
{
    int x;
    int y;

    x = (int)(e->playerx.x + 0.5);
    y = (int)(e->playerx.y + 0.5);
    while (e->playerx.y >= 0 && e->playerx.x >= 0
    && e->playerx.y < e->mapy && e->playerx.y < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
    {
        if ((e->rayang >= 270.0 && e->rayang <= 360.0)
        || (e->rayang >= 0.0 && e->rayang <= 90.0))
		{
			e->playerx.x++;
			e->playerx.y = e->playerx.y - ystep;
		}
		else
		{
			e->playerx.x--;
			e->playerx.y = e->playerx.y + ystep;
		}
        x = (int)(e->playerx.x + 0.5);
        y = (int)(e->playerx.y + 0.5);
    }
	e->playerx.y = e->playerx.y - e->player.y;
	e->playerx.x = e->playerx.x - e->player.x;
}

void dday(t_env *e, double xstep)
{
    int x;
    int y;

    x = (int)(e->playery.x + 0.5);
    y = (int)(e->playery.y + 0.5);
    while (e->playery.y >= 0 && e->playery.x >= 0
    && e->playery.y < e->mapy && e->playery.x < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
    {
        if (e->rayang >= 0.0 && e->rayang <= 180.0)
		{
        	e->playery.y--;
			e->playery.x = e->playery.x - xstep;
		}
		else
		{
			e->playery.y++;
        	e->playery.x = e->playery.x + xstep;
		}
        x = (int)(e->playery.x + 0.5);
        y = (int)(e->playery.y + 0.5);
    }
	e->playery.y = e->playery.y - e->player.y;
	e->playery.x = e->playery.x - e->player.x;
}

void		ft_dda(t_env *e)
{
    double ystep;
    double xstep;

	printf("rayang = %f\n", e->rayang);
    ystep = tan(e->rayang / e->pi);
    xstep = 1 / ystep;
    printf("xstep = %f, ystep = %f\n", xstep, ystep);
    e->playerx.x = 1.0 - (e->player.x - ((int)(e->player.x)));
    e->playerx.y = e->player.y + ystep * e->playerx.x;
    e->playerx.x = e->playerx.x + e->player.x;
	// e->playerx.x = e->player.x;
	// e->playerx.y = e->player.y;
	// e->playery.x = e->player.x;
	// e->playery.y = e->player.y;
    ddax(e, ystep);
	printf("e->playerx.x = %f, e->playerx.y = %f\n", e->playerx.x, e->playerx.y);
    // printf("ddax\n");
    e->playery.y = (e->player.y - ((int)(e->player.y)));
    e->playery.x = e->player.x + xstep * e->playery.y;
    e->playery.y = e->player.y - e->playery.y;
    dday(e, xstep);
	printf("e->playery.x = %f, e->playery.y = %f\n", e->playery.x, e->playery.y);
    // printf("dday\n");
    e->playery.y = e->playery.y * e->playery.y;
    e->playery.x = e->playery.x * e->playery.x;
    e->playerx.y = e->playerx.y * e->playerx.y;
    e->playerx.x = e->playerx.x * e->playerx.x;
    if (e->playery.y + e->playery.x <= e->playerx.y + e->playerx.x)
    {
        e->distx = e->playery.x;
        e->disty = e->playery.y;
		printf("y\n");
    }
    else
    {
        e->distx = e->playerx.x;
        e->disty = e->playerx.y;
		printf("x\n");
    }
}
