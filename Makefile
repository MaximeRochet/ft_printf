# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrochet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 12:17:01 by mrochet           #+#    #+#              #
#    Updated: 2021/03/09 11:27:45 by mrochet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/ft_c_to_str.c srcs/ft_free_char.c srcs/ft_init_struct.c\
				    srcs/ft_is_format.c srcs/ft_itoa_base_p.c\
					srcs/ft_itoa_base_u.c srcs/ft_itoa_base_x.c\
					srcs/ft_itoa_int.c srcs/ft_len_res_final.c\
					srcs/ft_parser.c srcs/ft_parser_annex.c\
					srcs/ft_print_res.c srcs/ft_printf.c srcs/ft_strdup_spe.c

LIBFT			=	libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c \
					libft/ft_putchar_fd.c libft/ft_split.c libft/ft_strlcat.c \
					libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c \
					libft/ft_isalpha.c libft/ft_itoa.c libft/ft_memcpy.c \
					libft/ft_putendl_fd.c libft/ft_strchr.c \
					libft/ft_strlcpy.c libft/ft_strnstr.c libft/ft_tolower.c \
					libft/ft_bzero.c   libft/ft_isascii.c libft/ft_memccpy.c \
					libft/ft_memmove.c libft/ft_putnbr_fd.c  libft/ft_strdup.c \
					libft/ft_strlen.c  libft/ft_strrchr.c libft/ft_toupper.c \
					libft/ft_calloc.c  libft/ft_isdigit.c libft/ft_memchr.c \
					libft/ft_memset.c libft/ft_putstr_fd.c \
					libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c \
					libft/ft_putnbr_base.c libft/ft_isdigit_0.c

OBJS			= $(SRCS:.c=.o) $(LIBFT:.c=.o)

CC				= @gcc
RM				= @/bin/rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "----MAKE----"

clean:
				$(RM) $(OBJS)
				@echo "----MAKE CLEAN----"

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
