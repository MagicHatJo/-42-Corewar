# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 14:24:50 by jochang           #+#    #+#              #
#    Updated: 2019/05/12 14:24:51 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC = acb_len \
	corewar \
	cwmem \
	display_winner \
	file_handler \
	ft_memrcpy \
	ft_putwchar \
	ft_setopt \
	init_cyc \
	init_mem \
	init_pc \
	op_fn \
	player_count \
	vm \
	pc_app \
	pc_free \
	pc_new \
	pc_scan_op \
	pc_scan_rem \
	op_add \
	op_aff \
	op_and \
	op_fork \
	op_ld \
	op_ldi \
	op_lfork \
	op_live \
	op_lld \
	op_lldi \
	op_or \
	op_st \
	op_sti \
	op_sub \
	op_xor \
	op_zjmp \
	err_invarg \
	err_invfile \
	err_invflag \
	err_invheader \
	err_invop \
	err_malloc \
	err_nofile \
	verify_cycle_bytes \
	cw_dump_mem \
	cw_dump_pcs \
	read_bytestring \
	debris \
	explosion \
	ft_prand \
	name \
	splash_screen \
	delete_gui \
	init_gui \
	print_breakdown \
	total_processes \
	update_gui \
	update_infoblock \
	update_memblock \

INC = -I ../inc \
	-I ../libft/inc \

LIB = -L ../libft -lft \
	-lncurses \
	-lm \

VPATH= src:pc:op:debug:gui:gui/splash:../err
OBJ_DIR = obj

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
MAKEOPTS = -j4

all: $(OBJ_DIR) $(NAME)

-include $(DEP)

$(OBJ_DIR):
	@printf "\033[32mmaking corewar objects\033[0m\n"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@make -C ../libft
	@$(CC) $^ -o $@ $(LIB)

clean:
	@printf "\033[33mcleaning corewar objects...\033[0m\n"
	@rm -f $(OBJ)
	@make -C ../libft clean

fclean: clean
	@printf "\033[33mcleaning corewar repository...\033[0m\n"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re
