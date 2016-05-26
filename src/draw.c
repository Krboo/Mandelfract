/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:35:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/26 11:30:21 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		sierpinski(t_env env, int x, int y)
{
	int		i;


	x = (( x + env.zx) * env.zx);
	y = (( y + env.zy) * env.zy);
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (255);
		x /= 3;
		y /= 3;
	}
	return (0);
}

static int		mandelbrot(t_env env, int x, int y)
{
	int		i;
	double	zr;
	double	zi;

	i = -1;
	env.f.pi = env.mod.ymax - (long double)y * env.zy;
	env.f.pr = env.mod.xmin + (long double)x * env.zx;
	env.f.ni = 0;
	env.f.nr = 0;
	zr = SQUARE(env.f.nr);
	zi = SQUARE(env.f.ni);
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni *= env.f.nr;
		env.f.ni += env.f.ni + env.f.pi;
		env.f.nr = zr - zi + env.f.pr;
		zr = SQUARE(env.f.nr);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}

static int		julia(t_env env, int x, int y)
{
	int				i;
	long double		zr;
	long double		zi;

	env.f.ni = env.mod.ymax - (long double)y * env.zy;
	env.f.nr = env.mod.xmin + (long double)x * env.zx;
	zr = SQUARE(env.f.nr);
	zi = SQUARE(env.f.ni);
	i = -1;
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni *= env.f.nr;
		env.f.ni += env.f.ni + env.f.ci;
		env.f.nr = zr - zi + env.f.cr;
		zr = SQUARE(env.f.nr);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}

static int		ft_fractal(t_env env, int x, int y)
{
	if (env.type == 1)
		return (mandelbrot(env, x, y));
	if (env.type == 2)
		return (julia(env, x, y));
	if (env.type == 3)
		return (sierpinski(env, x, y));
	else
		return (0);
}

int				draw(t_env env)
{
	int		color;
	int		pixel;
	int		x;
	int		y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pixel = ft_fractal(env, x, y);
			color = color_get(pixel, env);
			pixel_put(env, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	display(env);
	return (0);
}
