# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 14:24:50 by jochang           #+#    #+#              #
#    Updated: 2020/01/18 14:48:39 by smonroe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	corewar

SRC =	acb_len \
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
		player_count \
		vm \
		pc_app \
		pc_free \
		pc_new \
		pc_scan_op \
		pc_scan_rem \
		verify_cycle_bytes \
		cw_dump_mem \
		cw_dump_pcs \
		read_bytestring \
		wait_mod \
		wrappers \

OP =	op_fn \
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

ERR =	err_invarg \
		err_invfile \
		err_invflag \
		err_invheader \
		err_invop \
		err_malloc \
		err_nofile \

GUI =	debris \
		explosion \
		ft_prand \
		name \
		splash_screen \
		print_name \
		delete_gui \
		init_gui \
		print_info \
		print_breakdown \
		total_processes \
		update_gui \
		update_infoblock \
		update_memblock \

INC =	-I inc \
		-I ../lib/libft/inc \

LIB =	-L ../lib/libft -lft \
		-lncurses \
		-lm \

VPATH = src:pc:op:debug:gui:gui/splash:err
OBJ_DIR = obj

OBJ  = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(OP)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(ERR)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(GUI)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
MAKEOPTS = -j4

all: $(OBJ_DIR) $(NAME)

-include $(DEP)

$(OBJ_DIR):
	@printf "\033[32mMaking: Objects\033[0m\n"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@printf "\033[32mCompiling: \033[0m%s\n" $<
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@make -C ../lib/libft
	@printf "\033[32mLinking: \033[0m%s\n" $@
	@$(CC) $(CFLAGS) $^ -o $@ $(LIB)

clean:
	@printf "\033[33mCleaning: corewar objects...\033[0m\n"
	@rm -f $(OBJ)
	@make -C ../lib/libft clean

fclean: clean
	@printf "\033[33mCleaning: corewar repository...\033[0m\n"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make -C ../lib/libft fclean

re: fclean all

.PHONY: all clean fclean re
