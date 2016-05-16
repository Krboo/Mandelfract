/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:47:23 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/16 17:09:39 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int     ft_fractal(t_env env, int x, int y)
{
	if (env.type == 1)
		return (mandelbrot(env, x, y));
	if (env.type == 2)
		return (julia(env, x, y));
	if (env.type == 3)
		return (burning_ship(env, x, y));
	else
		return (0);
}

int     draw_f(t_env env)
{
	int        color;
	int        px;
	int        x;
	int        y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			px = ft_fractal(env, x, y);
			color = color_get(px, env);
			pixel_put(env, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	display(env);
	return (0);
}
