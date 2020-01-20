# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:40:53 by jochang           #+#    #+#              #
#    Updated: 2020/01/18 13:34:41 by smonroe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM :=	asm
CW	:=	corewar
ASM_DIR := assembler
CW_DIR := vm
CC = gcc

all:
	@make -C $(ASM_DIR)
	@make -C $(CW_DIR)
	@mv $(ASM_DIR)/bin/$(ASM) $(CW_DIR)/$(CW) .

clean:
	@make -C $(ASM_DIR) clean
	@make -C $(CW_DIR) clean

fclean:
	@make -C $(ASM_DIR) clean
	@make -C $(CW_DIR) clean
	@rm -f $(ASM)
	@rm -f $(CW)

re: fclean all

.PHONY: all clean fclean re
