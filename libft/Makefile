# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrochet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 16:01:43 by mrochet           #+#    #+#              #
#    Updated: 2020/12/02 16:34:03 by mrochet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memset.c ft_bzero.c\
	   ft_memcpy.c ft_memccpy.c \
	   ft_memmove.c ft_memchr.c \
	   ft_memcmp.c ft_strlen.c \
	   ft_isalpha.c ft_isdigit.c \
	   ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c \
	   ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c \
	   ft_strlcpy.c ft_strlcat.c \
	   ft_strnstr.c ft_atoi.c \
	   ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_strtrim.c \
	   ft_strmapi.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c \
	   ft_split.c ft_itoa.c \
	   ft_putnbr_fd.c ft_lstadd_front.c

BONUS = ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c

HEADER	= libft.h

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS	=	${BONUS:.c=.o}
RM		=	rm -f
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

%.o : %.c ${HEADER}	
	${CC} ${CFLAGS} -I includes -c $< -o $@

${NAME}:		${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM}  ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

bonus: 	${OBJS} ${OBJS_BONUS}
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
