# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 17:05:05 by prolling          #+#    #+#              #
#    Updated: 2021/07/11 17:18:50 by prolling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

sources = ft_memset.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_tolower.c ft_toupper.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memcmp.c ft_memcpy.c ft_calloc.c ft_memmove.c ft_memchr.c \
	ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_bzero.c ft_strdup.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c ft_putnbr_fd.c \
	ft_memccpy.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c \
	ft_strmapi.c
sources_bonus = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstadd_front.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c
sources_own = ft_isupper_bonus.c ft_islower_bonus.c ft_isspace_bonus.c \
	ft_putchar_bonus.c ft_putstr_bonus.c ft_putendl_bonus.c ft_putnbr_bonus.c \
	ft_strclen_bonus.c ft_add_bonus.c ft_sub_bonus.c ft_puts_bonus.c \
	ft_ctos_bonus.c
headers = libft.h

OBJS		=	$(sources) #$(sources:.c=.o)
OBJS_BONUS	=	$(sources_bonus) #$(sources_bonus:.c=.o)
OBJS_OWN	=	$(sources_own) #$(sources_own:.c=.o)

ifdef WITH_BONUS
	OBJ_SWITCH = $(OBJS) $(OBJS_BONUS)
else
	OBJ_SWITCH = $(OBJS)
endif

NAME = libft.a

FLAGS = -Wall -Wextra -Werror
CC = gcc
LIB = ar rc #su

$(NAME): clean
	gcc -c $(FLAGS) $(OBJ_SWITCH) $(OBJS_OWN)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o *.gch

all:  bonus $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 $(NAME)

devtest: $(NAME)
	gcc ../tests/testsuite.c -lft -L../src -o testsuite
	rm -f src/*.o src/*.gch

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all

so: clean
	gcc -shared -o libft.so $(OBJS) $(OBJS_BONUS) $(OBJS_OWN)

.PHONY:	all clean fclean re bonus
