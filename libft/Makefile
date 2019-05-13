# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 01:31:43 by jochang           #+#    #+#              #
#    Updated: 2019/04/18 08:11:32 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHK = ft_isalnum \
	  ft_isalpha \
	  ft_isascii \
	  ft_isdigit \
	  ft_isdir \
	  ft_isprint \
	  ft_isspace \
	  ft_placevalue \
	  ft_wordcount \
	  ft_wordlen \

CNV = ft_atoi \
	  ft_itoa \

BIT = ft_swapendian \
	  ft_swapnendian \
	  ft_swapendian64 \
	  ft_swapnendian64 \

GET = ft_getopt \
	  ft_getstdin \
	  ft_getnstdin \
	  ft_getwincols \
	  get_next_line \

LST = ft_lstadd \
	  ft_lstdel \
	  ft_lstdelone \
	  ft_lstiter \
	  ft_lstmap \
	  ft_lstnew \

MEM = ft_bzero \
	  ft_memalloc \
	  ft_memccpy \
	  ft_memchr \
	  ft_memcmp \
	  ft_memcpy \
	  ft_memdel \
	  ft_memmove \
	  ft_memset \
	  ft_realloc \

PUT = ft_putchar \
	  ft_putchar_fd \
	  ft_putendl \
	  ft_putendl_fd \
	  ft_putnbr \
	  ft_putnbr_fd \
	  ft_putnstr \
	  ft_putstr \
	  ft_putstr_fd \
	  ft_printmemory \

STR = ft_strcat \
	  ft_strccpy \
	  ft_strcdup \
	  ft_strcpy \
	  ft_strchr \
	  ft_strclr \
	  ft_strcmp \
	  ft_strdel \
	  ft_strdup \
	  ft_strequ \
	  ft_striter \
	  ft_striteri \
	  ft_strjoin \
	  ft_strlcat \
	  ft_strlen \
	  ft_strlower \
	  ft_strmap \
	  ft_strmapi \
	  ft_strncat \
	  ft_strncmp \
	  ft_strncpy \
	  ft_strndup \
	  ft_strnequ \
	  ft_strnew \
	  ft_strnstr \
	  ft_strrchr \
	  ft_strrev \
	  ft_strsplit \
	  ft_strstr \
	  ft_strsub \
	  ft_strtrim \
	  ft_strupper \
	  ft_tolower \
	  ft_toupper \

PRINTF = dispatch \
	  ft_printf \
	  get_opts \
	  pt_itoa_abs \
	  pt_itoh \
	  pt_itoo \
	  pt_putwchar \
	  pt_putwstr \
	  pt_uitoa \
	  pt_upval \
	  pt_wcslen \
	  d_s \
	  d_us \
	  d_p \
	  d_d \
	  d_ud \
	  d_o \
	  d_uo \
	  d_u \
	  d_uu \
	  d_x \
	  d_ux \
	  d_c \
	  d_uc \
	  d_percent \
	  d_b \

INC = -I inc

VPATH=chk:cnv:bit:get:lst:mem:put:str:ft_printf/src:ft_printf/type
SRC_DIR = .
OBJ_DIR = obj

OBJ  = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(CHK)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(CNV)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(BIT)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(GET)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(LST)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(MEM)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(PUT)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(STR)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(PRINTF)))

DEP = $(OBJ:%.o=%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
MAKEOPTS = -j4

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "\033[32mmaking libft objects...\033[0m"
	@mkdir -p $(OBJ_DIR)

-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[32mmaking libft...\033[0m"
	@ar -rcs $@ $^

clean:
	@echo "\033[33mcleaning libft repository...\033[0m"
	@rm -f $(OBJ) $(DEP)

fclean: clean
	@echo "\033[33mremoving libft library file...\033[0m"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
