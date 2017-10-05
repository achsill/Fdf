/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracedroite2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:24:41 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/04 14:11:10 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

void		line(t_data *data)
{
	int dx;
	int dy;
	int err;
	int c;

	c = -1;
	dx = data->x1 - data->x0;
	dy = data->y1 - data->y0;
	err = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	while (++c <= err)
	{
		put_pixel_to_img(data->x0 + (c * dx) / err, data->y0 + (c * dy) /
		err, data);
	}
}

void		line2(t_data *data)
{
	int dx;
	int dy;
	int err;
	int c;

	c = -1;
	dx = data->x1 - data->x0;
	dy = data->y1 - data->y0;
	err = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	while (++c <= err)
	{
		put_pixel_to_img(data->x0 + (c * dx) / err, data->y0 + (c * dy) /
		err, data);
	}
}
