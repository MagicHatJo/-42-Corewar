# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 06:50:56 by jochang           #+#    #+#              #
#    Updated: 2019/05/12 06:50:57 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASSEMBLER = asm
COREWAR = corewar

all: $(ASSEMBLER) $(COREWAR)

$(ASSEMBLER):
	@make -C assembler
	@mv assembler/asm .

$(COREWAR):
	@make -C vm
	@mv vm/corewar .

clean:
	@make -C assembler clean
	@make -C vm clean

fclean:
	@make -C assembler fclean
	@make -C vm fclean
	@rm -f $(ASSEMBLER) $(COREWAR)

re: clean all

.PHONY: all clean fclean re