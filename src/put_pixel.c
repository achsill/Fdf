/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:12:17 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/04 19:58:17 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_img(int x, int y, t_data *data)
{
	int i;

	if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
		return ;
	i = (x * data->bpp / 8) + (y * data->img_line);
	data->pixel_img[i] = data->r;
	data->pixel_img[i + 1] = data->g;
	data->pixel_img[i + 2] = data->b;
}

void	calculine(t_data *data, int x2, int y2)
{
	data->x0 = (x2 - y2) * data->zoom + data->xmid;
	data->y0 = ((x2 + y2) * (data->zoom / 2)
			+ data->ymid) - data->tab[y2][x2] * data->alt;
	data->x1 = ((x2 + 1) - y2) * data->zoom + data->xmid;
	data->y1 = (((x2 + 1) + y2)
			* (data->zoom / 2) + data->ymid) - data->tab[y2][x2 + 1] *
		data->alt;
	if (x2 + 1 < data->x)
		line(data);
}

void	calculine2(t_data *data, int x2, int y2)
{
	data->x0 = (x2 - y2) * data->zoom + data->xmid;
	data->y0 = ((x2 + y2) * (data->zoom / 2)
			+ data->ymid) - data->tab[y2][x2] * data->alt;
	data->x1 = (x2 - (y2 + 1)) * data->zoom + data->xmid;
	data->y1 = ((x2 + (y2 + 1))
			* (data->zoom / 2) + data->ymid) - data->tab[y2 + 1][x2]
		* data->alt;
	line2(data);
}

int		ftl_expose_hook(t_data *data)
{
	int	x2;
	int	y2;

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel_img = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->img_line), &(data->ed));
	x2 = 0;
	y2 = 0;
	while (y2 < data->y)
	{
		while (x2 < data->x)
		{
			if (x2 + 1 < data->x)
				calculine(data, x2, y2);
			if (y2 + 1 < data->y)
				calculine2(data, x2, y2);
			x2++;
		}
		x2 = 0;
		y2++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}
