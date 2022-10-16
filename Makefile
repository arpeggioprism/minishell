# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 19:01:09 by jiwkwon           #+#    #+#              #
#    Updated: 2022/10/16 22:48:42 by jshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_DIR = srcs/
OBJS_DIR = objs/
LIBFT_DIR = ./libft/
READ_LINE_DIR= $(shell brew --prefix readline)

SRCS =	$(SRCS_DIR)minishell.c \
		$(SRCS_DIR)ast/ast_command.c \
		$(SRCS_DIR)ast/ast_connecters.c \
		$(SRCS_DIR)ast/ast_linkedlist.c \
		$(SRCS_DIR)ast/ast_structures_geters.c \
		$(SRCS_DIR)ast/ast.c \
		$(SRCS_DIR)ast/display.c \
		$(SRCS_DIR)ast/redir.c \
		$(SRCS_DIR)builtins/cd.c \
		$(SRCS_DIR)builtins/echo.c \
		$(SRCS_DIR)builtins/env.c \
		$(SRCS_DIR)builtins/exit.c \
		$(SRCS_DIR)builtins/export.c \
		$(SRCS_DIR)builtins/pwd.c \
		$(SRCS_DIR)builtins/unset.c \
		$(SRCS_DIR)env/env_geters.c \
		$(SRCS_DIR)env/env.c \
		$(SRCS_DIR)etc/collector_linkedlist.c \
		$(SRCS_DIR)etc/history.c \
		$(SRCS_DIR)ex/ex.c \
		$(SRCS_DIR)ex/excommand.c \
		$(SRCS_DIR)ex/expander.c \
		$(SRCS_DIR)ex/signal.c \
		$(SRCS_DIR)ex/transfer.c \
		$(SRCS_DIR)parser/delete_quotes.c \
		$(SRCS_DIR)parser/parser_linkedlist.c \
		$(SRCS_DIR)parser/token_connecters.c \
		$(SRCS_DIR)parser/token_quotes.c \
		$(SRCS_DIR)parser/token_quotes_in_quotes.c \
		$(SRCS_DIR)parser/token_string.c \
		$(SRCS_DIR)parser/token_utils.c \
		$(SRCS_DIR)parser/token.c \
		$(SRCS_DIR)syntax/syntax_utils.c \
		$(SRCS_DIR)syntax/syntax.c \
		$(SRCS_DIR)utils/ft_itoa.c \
		$(SRCS_DIR)utils/ft_split.c \
		$(SRCS_DIR)utils/ft_strdup.c \
		$(SRCS_DIR)utils/ft_strjoin.c

OBJS = $(patsubst $(SRCS_DIR)%, $(OBJS_DIR)%, $(SRCS:.c=.o))

CC = cc
CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\033[34m[Compiling libft]\033[37m"
	make -C $(LIBFT_DIR)
	@echo "\n\033[94m[Making minishell]\033[37m"
	$(CC) $(CFLAG) -L$(READ_LINE_DIR)/lib -lreadline -L$(LIBFT_DIR) -lft -o $(NAME) $(OBJS)
	@echo "\033[32m\n...make Done!\n\033[37m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -I$(READ_LINE_DIR)/include -c $< -o $@

clean :
	@echo "\n\033[94m[Removing Object Files]\033[37m"
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	@echo "\033[32m\n...clean Done!\n\033[37m"

fclean : clean
	@echo "\033[94m[Removing Binary File]\033[37m"
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo "\033[32m\n...fclean Done!\n\033[37m"

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re
