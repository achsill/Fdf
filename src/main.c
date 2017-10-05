/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:14:28 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/04 20:05:47 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data			data;

	data.r = 255;
	data.g = 0;
	data.b = 255;
	data.xmid = 400;
	data.ymid = 400;
	data.zoom = 10;
	data.alt = 2;
	if (ac != 2)
		return (0);
	if (ft_compare(av[1], ".fdf") != 1)
		return (0);
	ft_parse(av[1], &data);
	if ((data.mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fdf")) == NULL)
		return (EXIT_FAILURE);
	mlx_expose_hook(data.win, ftl_expose_hook, &data);
	mlx_hook(data.win, 2, 1, ft_zoom, &data);
	mlx_loop(data.mlx);
	return (0);
}
