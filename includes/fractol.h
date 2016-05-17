/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:30:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/17 19:51:08 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "defines.h"

typedef struct      s_mod
{
	double          xmin;
	double          xmax;
	double          ymin;
	double          ymax;
	double          omx;
	double          omy;
}                   t_mod;

typedef struct      s_img
{
	void            *ptr;
	char            *img;
	int             bpp;
	int             ls;
	int             endian;
	int             width;
	int             height;
}                   t_img;

//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel

typedef struct      s_fract
{
	double          cr; //real part of the constant c
	double          ci; //imaginary part
	double          pr;
	double          pi;
	double          nrl; //new real
	double          ni; //new imaginary
	double          orl; //old real
	double          oi; //old imaginary
	double          zoom;
	double          mx; //movex
	double          my; //movey
}                   t_fract;

typedef struct      s_env
{
	void            *mlx;
	void            *win;
	int             type;
	int             motion;
	int             iter;
	int             color;
	int				display;
	double          freq;
	double          zx;
	double          zy;
	t_mod           mod;
	t_img           img;
	t_fract         f;
}                   t_env;

int                 ft_error(char *error);
t_env               init_env(char *type);
int                 ft_type(char *f);
int                 ft_keyhook(int keycode, t_env *env);
int                 ft_expose_hook(t_env *e);
int                 ft_fractal(t_env env, int x, int y);
int                 color_get(int i, t_env env);
void                pixel_put(t_env env, int x, int y, int clr);
int                 draw_f(t_env env);
int                 mandelbrot(t_env env, int x, int y);
int                 julia(t_env env, int x, int y);
int                 burning_ship(t_env env, int x, int y);
int                 ft_eventkey(int keycode, t_env *env);
t_env               *ft_reset(t_env *env);
int                 ft_mousehook(int button, int x, int y, t_env *env);
int                 ft_motionhook(int x, int y, t_env *env);
void                display(t_env e);

#endif
