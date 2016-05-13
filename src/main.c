/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:33:43 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/13 06:06:35 by pmartine         ###   ########.fr       */
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

	commands = "up / down / left / right : movements";
	mlx_string_put(e.mlx, e.win, 5, 5, 0xFBFBFB, commands);
	commands = "Mouse (Scroll wheel or left/right Buttons) : zoom / dezoom";
	mlx_string_put(e.mlx, e.win, 5, 20, 0xFBFBFB, commands);
	commands = "iterations : + / - (keypad)";
	mlx_string_put(e.mlx, e.win, 5, 35, 0xFBFBFB, commands);
	commands = "frequence : + / - (keyboard)";
	mlx_string_put(e.mlx, e.win, 5, 50, 0xFBFBFB, commands);
	commands = "change color palette : c";
	mlx_string_put(e.mlx, e.win, 5, 65, 0xFBFBFB, commands);
	commands = "motion (julia) : tab";
	mlx_string_put(e.mlx, e.win, 5, 80, 0xFBFBFB, commands);
}

int     main(int ac, char **av)
{
	t_env   env;

	if (ac != 2)
		ft_error("Usage : ./fractol 'fractale'\n(fractales : mandelbrot, julia, ship)");
	env = ft_init_env(av[1]);
	draw_f(env);
	display(env);
	mlx_key_hook(env.win, ft_keyhook, &env);
	mlx_mouse_hook(env.win, ft_mousehook, &env);
	mlx_hook(env.win, 6, 1L << 6, ft_motionhook, &env);
	mlx_loop(env.mlx);
}
