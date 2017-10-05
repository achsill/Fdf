/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:30:18 by hlouar            #+#    #+#             */
/*   Updated: 2016/02/16 16:13:40 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		lastjoin(char buff[BUFF_SIZE + 1], char **line)
{
	char	*dst;

	dst = ft_strsub(buff, 0, ft_ocur(buff, '\n'));
	line[0] = ft_joinfree(line[0], dst, 3);
	dst = ft_strsub(buff, ft_ocur(buff, '\n') + 1, BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	ft_strcpy(buff, dst);
	free(dst);
}

static	void	ft_initline(char **line)
{
	if (line[0] == NULL)
	{
		line[0] = (char *)malloc(sizeof(line[0]) * 2);
		ft_strcpy(line[0], "");
	}
	else
	{
		line[0] = NULL;
		ft_initline(line);
	}
}

static int		ft_read(int const fd, char **line)
{
	int			ret;
	static char	buff[NBR_FD][BUFF_SIZE + 1];

	if (ft_strlen(buff[fd]) == 0)
	{
		ret = read(fd, buff[fd], BUFF_SIZE);
		buff[fd][ret] = '\0';
		if (ret == 0 || ret == -1)
			return (ret);
	}
	if (ft_ocur(buff[fd], '\n') == -1)
	{
		line[0] = ft_joinfree(line[0], buff[fd], 1);
		ft_bzero(buff[fd], BUFF_SIZE);
		ft_read(fd, line);
	}
	else
		lastjoin(buff[fd], line);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int	ret;

	ret = -1;
	if (line == NULL)
		return (ret);
	if (fd >= 0 && fd < NBR_FD)
	{
		ft_initline(line);
		ret = ft_read(fd, line);
	}
	return (ret);
}
