# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 14:08:49 by jochang           #+#    #+#              #
#    Updated: 2019/05/12 14:08:49 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = arg \
	assembler \
	ft_strsplitwsp \
	get_bytecode \
	get_header \
	label \
	op \
	parser \
	t_byte \
	valid_extension \
	err_invarg \
	err_invfile \
	err_invflag \
	err_invheader \
	err_invop \
	err_malloc \
	err_nofile \

INC = -I ../inc \
	-I ../libft/inc \

LIB = -L ../libft -lft
VPATH= src:../err
OBJ_DIR = obj

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
MAKEOPTS = -j4

all: $(OBJ_DIR) $(NAME)

-include $(DEP)

$(OBJ_DIR):
	@printf "\033[32mmaking assembler objects\033[0m\n"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@make -C ../libft
	@$(CC) $^ -o $@ $(LIB)

clean:
	@printf "\033[33mcleaning assembler objects...\033[0m\n"
	@rm -f $(OBJ)
	@make -C ../libft clean

fclean: clean
	@printf "\033[33mcleaning assembler repository...\033[0m\n"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re