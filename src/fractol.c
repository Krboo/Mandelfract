/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:35:22 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/13 05:53:26 by pmartine         ###   ########.fr       */
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
	int                 clr;
	int                 px;
	register int        x;
	register int        y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			px = ft_fractal(env, x, y);
			clr = clr_get(px, env);
			pixel_put(env, x, y, clr);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	display(env);
	return (0);
}
