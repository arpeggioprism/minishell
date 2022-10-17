# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 21:26:45 by jiwkwon           #+#    #+#              #
#    Updated: 2022/10/17 11:27:43 by jshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./
OBJ_DIR = ../objs/libft/

SRC = ft_atoi.c ft_memset.c ft_putstr_fd.c ft_strcmp.c ft_strlen.c ft_strncmp.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
SRC := $(addprefix $(SRC_DIR), $(SRC))


AR = ar
ARFLAG = -rcs

CC = cc
CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAG) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
