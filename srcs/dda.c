/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:36:51 by idris             #+#    #+#             */
/*   Updated: 2020/01/24 09:05:34 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"


void ddax(t_env *e, double ystep)
{
    int x;
    int y;

    x = (int)(e->ddax.x);
    y = (int)(e->ddax.y);
    while (e->ddax.y >= 0 && e->ddax.x >= 0
    && e->ddax.y < e->mapy && e->ddax.y < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
    {
        if ((e->rayang >= 270.0 && e->rayang <= 360.0)
        || (e->rayang >= 0.0 && e->rayang <= 90.0))
		{
			e->ddax.x++;
			e->ddax.y = e->ddax.y - ystep;
		}
		else
		{
			e->ddax.x--;
			e->ddax.y = e->ddax.y + ystep;
		}
        x = (int)(e->ddax.x);
        y = (int)(e->ddax.y);
		// printf("ystep : %f\n", ystep);
    }
	e->ddax.y = e->ddax.y - e->player.y;
	e->ddax.x = e->ddax.x - e->player.x;
}

void dday(t_env *e, double xstep)
{
    int x;
    int y;

    x = (int)(e->dday.x);
    y = (int)(e->dday.y);
    while (e->dday.y >= 0 && e->dday.x >= 0
    && e->dday.y < e->mapy && e->dday.x < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
    {
        if (e->rayang >= 0.0 && e->rayang <= 180.0)
		{
        	e->dday.y--;
			e->dday.x = e->dday.x + xstep;
		}
		else
		{
			e->dday.y++;
        	e->dday.x = e->dday.x - xstep;
		}
        x = (int)(e->dday.x);
        y = (int)(e->dday.y);
    }
	e->dday.y = e->dday.y - e->player.y;
	e->dday.x = e->dday.x - e->player.x;
}

void		ft_dda(t_env *e)
{
    double ystep;
    double xstep;

	// printf("rayang = %f\n", e->rayang);
    ystep = tan(e->rayang / e->pi);
    xstep = 1 / ystep; //tan((90 - e->rayang) / e->pi);
    // printf("xstep = %f, ystep = %f\n", xstep, ystep);
	if ((e->rayang >= 270.0 && e->rayang <= 360.0)
    || (e->rayang >= 0.0 && e->rayang <= 90.0))
	{
		e->ddax.x = 1 - (e->player.x - ((int)(e->player.x)));
		// printf("e->ddax.x = %f\n",e->ddax.x);
		if ((int)e->ddax.x == 1)
		{
			e->ddax.y = e->player.y;
			e->ddax.x = e->player.x;
		}
		else
		{
			e->ddax.y = e->player.y - ystep * e->ddax.x;
			e->ddax.x = e->ddax.x + e->player.x;
		}
	}
	else
	{
		e->ddax.x = (e->player.x - ((int)(e->player.x)));
		e->ddax.y = e->player.y + ystep * e->ddax.x;
		e->ddax.x = (int)(e->player.x);
	}
	// e->ddax.x = e->player.x;
	// e->ddax.y = e->player.y;
	// e->dday.x = e->player.x;
	// e->dday.y = e->player.y;
	// printf("e->rayang = %f, e->player.x = %f, e->player.y = %f\n", e->rayang, e->player.x, e->player.y);
    ddax(e, ystep);
	// printf("e->ddax.x = %f, e->ddax.y = %f\n", e->ddax.x, e->ddax.y);
    // printf("ddax\n");
	if (e->rayang >= 0.0 && e->rayang <= 180.0)
	{
    	e->dday.y = (e->player.y - ((int)(e->player.y)));
    	e->dday.x = e->player.x + xstep * e->dday.y;
    	e->dday.y = (int)(e->player.y);
	}
	else
	{
		e->dday.y = 1 - (e->player.y - ((int)(e->player.y)));
		if ((int)e->dday.y == 1)
		{
			e->dday.x = e->player.x;
			e->dday.y = e->player.y;
		}
		else
		{
			e->dday.x = e->player.x - xstep * e->dday.y;
    		e->dday.y = e->player.y + e->dday.y;
		}
	}
    dday(e, xstep);
	// printf("e->dday.x = %f, e->dday.y = %f\n", e->dday.x, e->dday.y);
    // printf("dday\n");
    e->dday.y = e->dday.y * e->dday.y;
    e->dday.x = e->dday.x * e->dday.x;
	e->ddax.y = e->ddax.y * e->ddax.y;
    e->ddax.x = e->ddax.x * e->ddax.x;
    if (e->dday.y + e->dday.x <= e->ddax.y + e->ddax.x)
    {
        e->distx = e->dday.x;
        e->disty = e->dday.y;
		printf("y\n");
    }
    else
    {
        e->distx = e->ddax.x;
        e->disty = e->ddax.y;
		printf("x\n");
    }
}
