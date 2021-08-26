# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 08:48:58 by prolling          #+#    #+#              #
#    Updated: 2021/08/26 16:29:28 by prolling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
ARCH	= ar cr

headers = ft_printf.h
printf_src = ft_printf.c  ft_format.c ft_flags.c ft_apply_flags.c ft_utils.c\
	ft_safejoin.c ft_convert.c ft_convert_str.c ft_convert_char.c \
	ft_convert_int.c ft_convert_hex.c ft_convert_ptr.c ft_convert_per.c \
	ft_printstring.c ft_abs.c \

libft_src = libft/*.c libft/libft.h
debug = debug.c
phitest = ../phitest/*.c ../phitest/*.h

$(NAME): clean
	$(CC) -c $(FLAGS) $(headers) $(libft_src) $(printf_src)
	$(ARCH) $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o *.gch

bonus: $(NAME)

debug: tclean
	$(CC) -g -Wall -Wextra -Werror $(debug) $(headers) $(libft_src) $(printf_src) -o debug

phitest: tclean
	$(CC) -g -Wall -Wextra -Werror $(phitest) $(headers) $(libft_src) $(printf_src) -lcmocka -o phitest

all: $(NAME)

clean:
	rm -f *.o *.gch

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

tclean: fclean
	rm -f phitest
	rm -f debug

re : fclean tclean all

.PHONY:	all clean fclean re
