/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:48:18 by hlouar            #+#    #+#             */
/*   Updated: 2016/03/04 19:57:32 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct		s_data
{
	int				dy;
	int				dx;
	int				stepx;
	int				stepy;
	int				x;
	int				y;
	void			*win;
	void			*mlx;
	int				color;
	int				**tab;
	char			*pixel_img;
	int				ed;
	int				img_line;
	int				bpp;
	void			*img;
	int				alt;
	int				zoom;
	int				xmid;
	int				ymid;
	int				r;
	int				g;
	int				b;
	int				r2;
	int				g2;
	int				b2;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_data;

int					ft_strlenchar(char *str, char c);
void				ft_parse(char *str, t_data *data);
int					ftl_expose_hook(t_data *data);
void				put_pixel_to_img(int x, int y, t_data *data);
void				line(t_data *data);
int					ft_zoom(int keycode, t_data *data);
void				line2(t_data *data);
void				calculine(t_data *data, int x2, int y2);
void				calculine2(t_data *data, int x2, int y2);
int					ftl_expose_hook(t_data *data);
int					ft_bordel(int i, t_data *data);
int					ft_oe(int i, t_data *data);
int					ft_compare(char *str, char *dst);

#endif
