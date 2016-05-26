/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:30:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/26 18:10:28 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "defines.h"

typedef struct	s_mod
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	omx;
	double	omy;
}				t_mod;

typedef struct	s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		ls;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_fract
{
	double	cr;
	double	ci;
	double	nr;
	double	ni;
	double	orl;
	double	oi;
	double	pr;
	double	pi;
	double	mx;
	double	my;
}				t_fract;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		type;
	int		motion;
	int		iter;
	int		color;
	int		display;
	int		values;
	double	freq;
	double	zx;
	double	zy;
	t_mod	mod;
	t_img	img;
	t_fract	f;
}				t_env;

void			display(t_env e);
t_env			init_env(char *type);
t_env			*ft_reset(t_env *env);
int				ft_error(char *error);
int				ft_arg(char *f);
int				ft_keyhook(int keycode, t_env *env);
int				ft_expose_hook(t_env *e);
int				color_get(int i, t_env env);
void			pixel_put(t_env env, int x, int y, int clr);
int				draw(t_env env);
int				ft_mousehook(int button, int x, int y, t_env *env);
int				ft_juliahook(int x, int y, t_env *env);
#endif
