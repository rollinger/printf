# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 08:48:58 by prolling          #+#    #+#              #
#    Updated: 2021/07/11 11:06:29 by prolling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
ARCH	= ar cr

headers = ft_printf.h
printf_src = ft_printf.c ft_utils.c
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
