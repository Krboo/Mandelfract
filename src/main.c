/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:33:43 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/17 23:16:06 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	display(t_env e)
{
	char	*commands;
	
	if (e.display == 1)
	{
		commands = "Zoom : scroll wheel or mouse buttons";
		mlx_string_put(e.mlx, e.win, 5, 5, 0xFBFBFB, commands);
		commands = "Movements : Arrow Keys";
		mlx_string_put(e.mlx, e.win, 5, 20, 0xFBFBFB, commands);
		commands = "Iterations : +/- (keypad)";
		mlx_string_put(e.mlx, e.win, 5, 35, 0xFBFBFB, commands);
		commands = "Frequence : pageup / pagedown)";
		mlx_string_put(e.mlx, e.win, 5, 50, 0xFBFBFB, commands);
		commands = "Stop motion (julia) : tab";
		mlx_string_put(e.mlx, e.win, 5, 65, 0xFBFBFB, commands);
		commands = "Change color palette : c";
		mlx_string_put(e.mlx, e.win, 5, 80, 0xFBFBFB, commands);
		commands = "Reset fractal : return";
		mlx_string_put(e.mlx, e.win, 5, 95, 0xFBFBFB, commands);
		commands = "Change fractal : space";
		mlx_string_put(e.mlx, e.win, 5, 110, 0xFBFBFB, commands);
		commands = "Hide / display this menu : clear";
		mlx_string_put(e.mlx, e.win, 5, 125, 0xFBFBFB, commands);
	}
}

int     main(int ac, char **av)
{
	t_env   env;

	if (ac != 2)
		ft_error("Usage : ./fractol 'fractal'\n\nAvailable fractals :\n- mandelbrot\n- julia");
	env = init_env(av[1]);
	draw_f(env);
	display(env);
	mlx_key_hook(env.win, ft_keyhook, &env);
	mlx_mouse_hook(env.win, ft_mousehook, &env);
	mlx_hook(env.win, 6, 1L << 6, ft_motionhook, &env);
	mlx_loop(env.mlx);
}
