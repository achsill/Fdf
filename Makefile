# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlouar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 15:40:57 by hlouar            #+#    #+#              #
#    Updated: 2016/03/04 19:58:40 by hlouar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/parse.c src/tracedroite.c src/put_pixel.c src/shortcut.c src/main.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBS = src/libft.a

GNL = src/get_next_line.c

FLAGMLX = -lmlx -framework Opengl -framework AppKit

all: $(NAME)

$(NAME):$(OBJ)
		gcc $(FLAG) -o $(NAME) $(FLAGMLX) $(GNL) $(SRC) $(LIBS) -I.

clean:
		/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
