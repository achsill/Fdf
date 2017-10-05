/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:10:34 by hlouar            #+#    #+#             */
/*   Updated: 2016/02/15 17:25:40 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 8
# define NBR_FD 100

int	get_next_line(int const fd, char **line);

#endif
