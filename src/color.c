/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:40:26 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/13 06:06:04 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    pixel_put(t_env env, int x, int y, int clr)
{
	int     pos;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		pos = (x * env.img.bpp / 8) + (y * env.img.ls);
		env.img.img[pos] = clr % 256;
		env.img.img[pos + 1] = (clr >> 8) % 256;
		env.img.img[pos + 2] = (clr >> 16) % 256;
	}
}

int     clr_get(int i, t_env env)
{
	register double c;
	register int    r;
	register int    g;
	register int    b;

	if (i == env.iter)
		return (0);
	c = env.freq * (i);
	r = cos(c) * 127 + 128;
	g = cos(c + env.color) * 127 + 128;
	b = cos(c + env.color + env.color) * 127 + 128;
	return ((r << 16) + (b << 8) + g);
}
