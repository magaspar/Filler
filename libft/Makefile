# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/12 17:27:51 by magaspar     #+#   ##    ##    #+#        #
#    Updated: 2018/03/22 15:30:49 by magaspar    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: fclean clean make re all

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_bite_uni.c \
	   src/ft_c_uni.c \
	   src/ft_error.c \
	   src/ft_l.c \
	   src/ft_o.c \
	   src/ft_o_u_x.c \
	   src/ft_pour_sang.c \
	   src/ft_pres.c \
	   src/ft_printf.c \
	   src/ft_printf_tree.c \
	   src/ft_seeker.c \
	   src/ft_ss.c \
	   src/ft_wchatte.c \
	   src/ft_x_movie.c \
	   src/utilities.c \
	   src/ft_ptwp.c \
	   src/ft_itoa_base_u.c \

LIB = 	fonc/ft_memset.c fonc/ft_bzero.c fonc/ft_memcpy.c \
		fonc/ft_memccpy.c fonc/ft_memmove.c \
		fonc/ft_memchr.c fonc/ft_memcmp.c fonc/ft_strlen.c \
		fonc/ft_strdup.c fonc/ft_strcpy.c \
		fonc/ft_strncpy.c fonc/ft_strcat.c fonc/ft_strncat.c \
		fonc/ft_strlcat.c fonc/ft_strchr.c \
		fonc/ft_strrchr.c fonc/ft_strstr.c fonc/ft_strnstr.c \
		fonc/ft_strcmp.c fonc/ft_strncmp.c \
		fonc/ft_atoi.c fonc/ft_isalpha.c fonc/ft_isdigit.c \
		fonc/ft_isalnum.c fonc/ft_isascii.c \
		fonc/ft_isprint.c fonc/ft_toupper.c fonc/ft_tolower.c \
		fonc/ft_putchar.c fonc/ft_putstr.c \
		fonc/ft_memalloc.c fonc/ft_memdel.c fonc/ft_strnew.c \
		fonc/ft_strdel.c fonc/ft_strclr.c \
		fonc/ft_striter.c fonc/ft_striteri.c fonc/ft_strmap.c \
		fonc/ft_strmapi.c fonc/ft_strequ.c \
		fonc/ft_strnequ.c fonc/ft_strsub.c fonc/ft_strjoin.c \
		fonc/ft_strtrim.c fonc/ft_strsplit.c \
		fonc/ft_itoa.c fonc/ft_putendl.c fonc/ft_putnbr.c \
		fonc/ft_putchar_fd.c fonc/ft_putstr_fd.c \
		fonc/ft_putendl_fd.c fonc/ft_putnbr_fd.c \
		fonc/ft_lstnew.c fonc/ft_lstdelone.c \
		fonc/ft_lstdel.c fonc/ft_lstadd.c fonc/ft_lstiter.c \
		fonc/ft_lstmap.c fonc/ft_strjoinf.c \
		fonc/ft_strsubf.c fonc/ft_realloc.c fonc/get_next_line.c \
		fonc/ft_pow.c fonc/ft_sqrt.c fonc/ft_max.c

OBJS = $(SRCS:.c=.o) $(LIB:.c=.o)

all: $(NAME)

./%.o:./%.c includes/ft_printf.h
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
