# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 08:48:58 by prolling          #+#    #+#              #
#    Updated: 2021/07/14 19:30:36 by prolling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
ARCH	= ar cr

headers = ft_printf.h
printf_src = ft_sprintf.c ft_utils.c ft_format.c ft_convert.c \
	ft_convert_str.c ft_convert_char.c ft_convert_int.c ft_convert_hex.c \
	ft_convert_ptr.c
libft_src = libft/*.c libft/libft.h
debug = debug.c

$(NAME): clean
	$(CC) -c $(FLAGS) $(headers) $(libft_src) $(printf_src)
	$(ARCH) $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o *.gch

debug: $(NAME)
	$(CC) -g -Wall -Wextra -Werror $(debug) $(headers) -lftprintf -L. -o debug

all: $(NAME)

clean:
	rm -f *.o *.gch

fclean: cleanlibft/libft.h
	cd libft && make fclean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
