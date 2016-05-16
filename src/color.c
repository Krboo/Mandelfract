/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:40:26 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/16 21:57:11 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    pixel_put(t_env env, int x, int y, int color)
{
	int     index;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		index = (x * env.img.bpp / 8) + (y * env.img.ls);
		env.img.img[index] = color % 256;
		env.img.img[index + 1] = (color >> 8) % 256;
		env.img.img[index + 2] = (color >> 16) % 256;
	}
}

int     color_get(int i, t_env env)
{
	double c;
	int    r;
	int    g;
	int    b;

	if (i == env.iter)
		return (0);
	c = env.freq * (i);
	r = cos(c) * 100 + 256;
	g = cos(c + env.color) * 100 + 256;
	b = cos(c + env.color + env.color) * 100 + 256;
	return ((r << 16) + (b << 8) + g);
}
