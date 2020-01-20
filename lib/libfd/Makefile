# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 19:31:23 by jochang           #+#    #+#              #
#    Updated: 2019/09/29 19:31:24 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libfd.a

DEQUE =	deque_init \
		deque_begin \
		deque_end \
		deque_size \
		deque_empty \
		deque_at \
		deque_front \
		deque_back \
		deque_push_back \
		deque_push_front \
		deque_pop_back \
		deque_pop_front \

QUEUE =	queue_init \
		queue_empty \
		queue_size \
		queue_front \
		queue_back \
		queue_push \
		queue_pop \

SRC =	$(DEQUE) $(QUEUE)

INC =	-I inc

LIB =

VPATH = deque:queue

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

DEP = $(OBJ:%.o=%.d)

CC = gcc
#CC = clang-6.0
CFLAGS = -Wall -Wextra -Werror $(INC)
LDFLAGS = $(LIB)
MAKEOPTS = -j4

.PHONY: all
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@printf "\033[32mCreating: \033[0m%s\n" $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)

-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	@printf "\033[32mCompiling: \033[0m%s\n" $<
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@printf "\033[32mLinking: \033[0m%s\n" $(NAME)
	@ar -rcs $@ $^

.PHONY: clean
clean:
	@printf "\033[33mCleaning: \033[0m%s repository\n" $(NAME)
	@ rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@printf "\033[33mCleaning: \033[0m%s\n" $(BIN_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME).dSYM
	@rm -f $(NAME)

.PHONY: re
re: fclean all
