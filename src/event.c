/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:36:18 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/18 20:31:11 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_keyhook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	else
		ft_eventkey(keycode, env);
	return (0);
}

void	ft_arrow_keys(t_env *env, int keycode)
{
	const double k = env->zx * 10;

	if (keycode == UP)
	{
		env->mod.ymax -= k;
		env->mod.ymin -= k;
	}
	else if (keycode == DOWN)
	{
		env->mod.ymax += k;
		env->mod.ymin += k;
	}
	else if (keycode == RIGHT)
	{
		env->mod.xmax -= k;
		env->mod.xmin -= k;
	}
	else if (keycode == LEFT)
	{
		env->mod.xmax += k;
		env->mod.xmin += k;
	}
	env->zy = ((env->mod.ymax - env->mod.ymin) / (H - 1));
	env->zx = ((env->mod.xmax - env->mod.xmin) / (W - 1));
}

int		ft_color_hook(int keycode, int *color)
{
	if (keycode == 69)
		color++;
	if (keycode == 78)
		color--;
	return (0);
}

int		ft_eventkey(int keycode, t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == INC_ITER)
		env->iter *= (env->iter < 10000) ? 2 : 1;
	else if (keycode == DEC_ITER)
		env->iter /= (env->iter > 2) ? 2 : 1;
	else if (keycode == INC_FREQ)
		env->freq *= 2;
	else if (keycode == DEC_FREQ && env->freq > 0.1)
		env->freq /= 2;
	else if (keycode == CHANGE_FRACT && (env = ft_reset(env)))
		env->type = (env->type == 2) ? 1 : 2;
	else if (keycode == RESET)
		env = ft_reset(env);
	else if (keycode == MOTION)
		env->motion = (env->motion == 1) ? 0 : 1;
	else if (keycode == C)
		env->color++;
	else if (keycode == MENU)
		env->display = (env->display == 1) ? 0 : 1;
	else if (keycode == VALUES)
		env->values = (env->values == 1) ? 0 : 1;
	ft_arrow_keys(env, keycode);
	draw_f(*env);
	return (0);
}
