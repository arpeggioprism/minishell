# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 19:01:09 by jiwkwon           #+#    #+#              #
#    Updated: 2022/10/17 11:10:40 by jshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
BONUS = minishell_bonus

SRCS_DIR = srcs/
SRCS_DIR_BONUS = srcs_bonus/
OBJS_DIR = objs/
OBJS_DIR_BONUS = objs_bonus/
LIBFT_DIR = ./libft/
READ_LINE_DIR= $(shell brew --prefix readline)

SRCS_MANDA = $(SRCS_DIR)minishell.c \
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
			 $(SRCS_DIR)execute/ex.c \
			 $(SRCS_DIR)execute/excommand.c \
			 $(SRCS_DIR)execute/expander.c \
			 $(SRCS_DIR)execute/signal.c \
			 $(SRCS_DIR)execute/transfer.c \
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

SRCS_BONUS = $(SRCS_DIR_BONUS)minishell_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/ast_command_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/ast_connecters_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/ast_linkedlist_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/ast_structures_geters_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/ast_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/display_bonus.c \
			 $(SRCS_DIR_BONUS)ast_bonus/redir_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/cd_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/echo_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/env_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/exit_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/export_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/pwd_bonus.c \
			 $(SRCS_DIR_BONUS)builtins_bonus/unset_bonus.c \
			 $(SRCS_DIR_BONUS)env_bonus/env_geters_bonus.c \
			 $(SRCS_DIR_BONUS)env_bonus/env_bonus.c \
			 $(SRCS_DIR_BONUS)etc_bonus/collector_linkedlist_bonus.c \
			 $(SRCS_DIR_BONUS)etc_bonus/history_bonus.c \
			 $(SRCS_DIR_BONUS)etc_bonus/init_bonus.c \
			 $(SRCS_DIR_BONUS)execute_bonus/ex_bonus.c \
			 $(SRCS_DIR_BONUS)execute_bonus/excommand_bonus.c \
			 $(SRCS_DIR_BONUS)execute_bonus/expander_bonus.c \
			 $(SRCS_DIR_BONUS)execute_bonus/signal_bonus.c \
			 $(SRCS_DIR_BONUS)execute_bonus/transfer_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/delete_quotes_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/parser_linkedlist_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/token_connecters_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/token_quotes_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/token_quotes_in_quotes_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/token_string_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/token_utils_bonus.c \
			 $(SRCS_DIR_BONUS)parser_bonus/token_bonus.c \
			 $(SRCS_DIR_BONUS)syntax_bonus/syntax_utils_bonus.c \
			 $(SRCS_DIR_BONUS)syntax_bonus/syntax_bonus.c \
			 $(SRCS_DIR_BONUS)utils_bonus/ft_itoa_bonus.c \
			 $(SRCS_DIR_BONUS)utils_bonus/ft_split_bonus.c \
			 $(SRCS_DIR_BONUS)utils_bonus/ft_strdup_bonus.c \
			 $(SRCS_DIR_BONUS)utils_bonus/ft_strjoin_bonus.c

OBJS_MANDA = $(patsubst $(SRCS_DIR)%, $(OBJS_DIR)%, $(SRCS_MANDA:.c=.o))

OBJS_BONUS = $(patsubst $(SRCS_DIR_BONUS)%, $(OBJS_DIR_BONUS)%, $(SRCS_BONUS:.c=.o))

CC = cc
CFLAG = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS = $(OBJS_BONUS)
SRCS_DIR =$(SRCS_DIR_BONUS)
OBJS_DIR = $(OBJS_DIR_BONUS)
NAME = $(BONUS)
else
OBJS = $(OBJS_MANDA)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\033[36m[Compiling libft]\033[37m"
	make -C $(LIBFT_DIR)
	@echo "\n\033[36m[Making minishell]\033[37m"
	$(CC) $(CFLAG) -L$(READ_LINE_DIR)/lib -lreadline -L$(LIBFT_DIR) -lft -o $(NAME) $(OBJS)
	@echo "\033[32m\n...make Done!\n\033[37m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -I$(READ_LINE_DIR)/include -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	@echo "\n\033[36m[Removing Object Files]\033[37m"
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_MANDA) $(OBJS_BONUS)
	rm -rf $(OBJS_DIR) $(OBJS_DIR_BONUS)
	@echo "\033[32m\n...clean Done!\n\033[37m"

fclean : clean
	@echo "\033[36m[Removing Binary File]\033[37m"
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS)
	@echo "\033[32m\n...fclean Done!\n\033[37m"

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re
