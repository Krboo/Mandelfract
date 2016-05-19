/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:34:46 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/19 14:51:49 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		ft_init_mouse(t_env *env, double dcr, double dci)
{
	dcr = env->f.cr / 2;
	dci = env->f.ci / 2;
	env->mod.xmin = env->f.mx - dcr;
	env->mod.xmax = env->f.mx + dcr;
	env->mod.ymin = env->f.my - dci;
	env->mod.ymax = env->f.my + dci;
	env->zy = ((env->mod.ymax - env->mod.ymin) / (H - 1));
	env->zx = ((env->mod.xmax - env->mod.xmin) / (W - 1));
}

int				ft_juliahook(int x, int y, t_env *env)
{
	if (x >= 0 && y >= 0 && x <= W && y <= H && env->type == 2 && \
			env->motion == 1)
	{
		env->f.ci = env->mod.ymax - (double)y * env->zy;
		env->f.cr = env->mod.xmin + (double)x * env->zx;
	}
	else
		return (0);
	return (draw(*env));
}

int				ft_mousehook(int button, int x, int y, t_env *env)
{
	double	dcr;
	double	dci;

	dcr = x;
	dci = y;
	env->f.cr = env->mod.xmax - env->mod.xmin;
	env->f.ci = env->mod.ymax - env->mod.ymin;
	env->f.mx = ((double)x / W * env->f.cr) - env->f.cr / 2 + env->f.mx;
	env->f.my = (double)(H - y) / H * env->f.ci - env->f.ci / 2 + env->f.my;
	if ((button == 1 || button == 4) && x <= W && y <= H)
	{
		env->f.cr /= 1.5;
		env->f.ci /= 1.5;
	}
	else if ((button == 2 || button == 5) && x <= W && y <= H)
	{
		env->f.cr *= 1.5;
		env->f.ci *= 1.5;
	}
	ft_init_mouse(env, dcr, dci);
	return (draw(*env));
}
