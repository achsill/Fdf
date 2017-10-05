/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:13:58 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/04 19:58:20 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		strlenchar(char *str, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		i++;
	}
	return (count);
}

static void		ft_infos(char *str, t_data *data, char *line)
{
	int		fd;
	int		i;
	int		o;
	int		e;

	e = 0;
	o = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		o = strlenchar(line, ' ');
	}
	if (o > e)
	{
		e = o;
		o = 0;
	}
	data->x = e;
	data->y = i;
	close(fd);
}

static void		create_tab(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	data->tab = (int **)malloc(sizeof(int*) * data->y);
	while (y < data->y)
	{
		data->tab[y] = (int*)malloc(sizeof(int) * data->x);
		y++;
	}
}

static void		fill(char *line, t_data *data, int fd)
{
	int x;
	int y;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		while (x < data->x)
		{
			if (ft_strchr("0123456789-", *line))
			{
				data->tab[y][x++] = ft_atoi(line);
				while (ft_strchr("0123456789-", *line))
					line++;
			}
			if (x < data->x)
				line++;
		}
		y++;
	}
}

void			ft_parse(char *str, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	ft_infos(str, data, line);
	fd = open(str, O_RDONLY);
	create_tab(data);
	fill(str, data, fd);
	close(fd);
}
