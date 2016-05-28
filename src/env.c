/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:47:10 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/27 16:02:30 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_env				*ft_reset(t_env *env)
{
	env->mod.xmax = 2.00;
	env->mod.xmin = -2.00;
	env->mod.ymin = -2.00;
	env->mod.ymax = 2.00;
	env->f.cr = -0.75;
	env->f.ci = 0.37015;
	env->f.mx = 0.00;
	env->f.my = 0.00;
	env->f.nr = 0.00;
	env->f.ni = 0.00;
	env->freq = 0.10;
	env->iter = 16;
	env->color = 2;
	env->motion = 1;
	env->zx = ((env->mod.xmax - env->mod.xmin) / (W - 1));
	env->zy = ((env->mod.ymax - env->mod.ymin) / (H - 1));
	return (env);
}

int static			ft_argv(char *f)
{
	if (ft_strcmp(f, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(f, "julia") == 0)
		return (2);
	if (ft_strcmp(f, "mandelbar") == 0)
		return (3);
	return (ft_error("Availables :\n- mandelbrot\n- julia\n- mandelbar"));
}

void static			init_fract(t_env *env)
{
	env->f.cr = -0.75;
	env->f.ci = 0.37015;
	env->f.mx = 0.00;
	env->f.my = 0.00;
	env->f.nr = 0.00;
	env->f.ni = 0.00;
	env->mod.xmax = 2.00;
	env->mod.xmin = -2.00;
	env->mod.ymin = -2.00;
	env->mod.ymax = 2.00;
}

t_env				init_env(char *type)
{
	t_env	env;

	init_fract(&env);
	env.zx = ((env.mod.xmax - env.mod.xmin) / (W - 1));
	env.zy = ((env.mod.ymax - env.mod.ymin) / (H - 1));
	env.type = ft_argv(type);
	env.display = 1;
	env.values = 0;
	env.iter = 16;
	env.freq = 0.1;
	env.color = 2;
	env.motion = 1;
	env.img.width = W;
	env.img.height = H;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, W, H, "Fractol");
	env.img.ptr = mlx_new_image(env.mlx, env.img.width, env.img.height);
	env.img.img = mlx_get_data_addr(env.img.ptr, \
	&env.img.bpp, &env.img.ls, &env.img.endian);
	return (env);
}
