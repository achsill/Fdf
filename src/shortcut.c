/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:42:49 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/04 18:49:40 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	winhelp(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 700, 700, "SHORTCUT");
	mlx_string_put(mlx, win, 320, 10, 0xFF00FF, "SHORTCUT :");
	mlx_string_put(mlx, win, 20, 600, 0xFF0000,
			"fleches directionnelles = deplacer la map");
	mlx_string_put(mlx, win, 20, 150, 0xFFFF00,
			"+ / - = ajoutez de l'altitude / enlever de l'altitude");
	mlx_string_put(mlx, win, 20, 300, 0xFF0000,
			"page up / page down = zoomer / dezoomer");
	mlx_string_put(mlx, win, 20, 450, 0xFFFF00,
			"1 / 2 / 3 = changer la couleur de la map");
	mlx_loop(mlx);
}

int		ft_claudio(int keycode, t_data *data)
{
	if (keycode == 116)
		data->zoom += 5;
	if (keycode == 121 && data->zoom > 5)
		data->zoom -= 5;
	if (keycode == 126)
		data->ymid -= 10;
	if (keycode == 125)
		data->ymid += 5;
	if (keycode == 123)
		data->xmid -= 7;
	if (keycode == 124)
		data->xmid += 10;
	return (0);
}

int		ft_zoom(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
		data->alt++;
	if (keycode == 78)
		data->alt--;
	if (keycode >= 116 && keycode <= 126)
		ft_claudio(keycode, data);
	if (keycode == 264)
		winhelp();
	if (keycode == 19)
		ft_bordel(2, data);
	if (keycode == 18)
		ft_bordel(1, data);
	if (keycode == 20)
		ft_bordel(3, data);
	ftl_expose_hook(data);
	return (1);
}

int		ft_bordel(int i, t_data *data)
{
	if (i == 1)
	{
		data->r = 255;
		data->g = 0;
		data->b = 255;
	}
	if (i == 2)
	{
		data->r = 250;
		data->g = 0;
		data->b = 0;
	}
	if (i == 3)
	{
		data->r = 0;
		data->g = 250;
		data->b = 250;
	}
	return (0);
}

int		ft_compare(char *str, char *dst)
{
	int i;
	int o;
	int k;

	o = ft_strlen(dst);
	i = ft_strlen(str);
	k = 0;
	while (i > 0)
	{
		while ((str[i]) == (dst[o]))
		{
			if (k == 4)
				return (1);
			k++;
			o--;
			i--;
		}
		o--;
		i--;
	}
	return (0);
}
