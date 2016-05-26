/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:33:43 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/26 13:51:14 by pmartine         ###   ########.fr       */
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
		commands = "Zoom : scroll wheel/buttons (Mouse)";
		mlx_string_put(e.mlx, e.win, 5, 5, 0xFFFFFF, commands);
		commands = "Movements : Arrow Keys";
		mlx_string_put(e.mlx, e.win, 5, 22, 0xFFFFFF, commands);
		commands = "Iterations : +/- (keypad)";
		mlx_string_put(e.mlx, e.win, 5, 39, 0xFFFFFF, commands);
		commands = "Frequence : pageup / pagedown";
		mlx_string_put(e.mlx, e.win, 5, 56, 0xFFFFFF, commands);
		commands = "Enable/Disable motion (julia) : space";
		mlx_string_put(e.mlx, e.win, 5, 73, 0xFFFFFF, commands);
		commands = "Change color palette : c";
		mlx_string_put(e.mlx, e.win, 5, 91, 0xFFFFFF, commands);
		commands = "Reset fractal : clear";
		mlx_string_put(e.mlx, e.win, 5, 108, 0xFFFFFF, commands);
		commands = "Change fractal : tab";
		mlx_string_put(e.mlx, e.win, 5, 125, 0xFFFFFF, commands);
		commands = "Hide/Display inputs : return";
		mlx_string_put(e.mlx, e.win, 5, 142, 0xFFFFFF, commands);
	}
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_error("Usage : ./fractol 'fractal'\nAvailable fractals :\n- \
mandelbrot\n- julia\n- mandelbar");
	env = init_env(av[1]);
	draw(env);
	display(env);
	mlx_hook(env.win, 2, 2, ft_keyhook, &env);
	mlx_mouse_hook(env.win, ft_mousehook, &env);
	mlx_hook(env.win, 6, (1L << 0), ft_juliahook, &env);
	mlx_loop(env.mlx);
}
