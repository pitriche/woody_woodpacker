# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:21:44 by pitriche          #+#    #+#              #
#    Updated: 2021/06/14 13:23:49 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY    = \033[030m
RED     = \033[031m
GREEN   = \033[032m
YELLOW  = \033[033m
BLUE    = \033[034m
MAGENTA = \033[035m
CYAN	= \033[036m
RESET   = \033[0m

# ############################################################################ #

CC = gcc

FL_OPTI = -O2
#-O3 -flto
FLAGS = -Wall -Wextra -Wconversion -Wunused -Wuninitialized $(FL_OPTI)
LFLAGS = $(FLAGS)
CFLAGS = -c $(FLAGS)

CINCLUDE = -I include

# ############################################################################ #

NAME = woody_woodpacker

HEADERS = \
#include/scop.h		\


SRC_FILES = 	\
main.c		\

# ############################################################################ #

SRC_DIR = src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ_DIR = obj/
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_FILES))


all: $(NAME)
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "$(GREEN)objects done sir !$(RESET)"
	@$(CC) $(FRAMEWORKS) $(LFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled sir !$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CINCLUDE) $(CFLAGS) -o $@ $<
	@echo -n '.'

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@echo "$(GREEN)Object directory created sir !$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects deleted sir !$(RESET)"
	@rm -rf $(OBJ_DIR)
	@#echo "$(RED)Object directory deleted sir !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted sir !$(RESET)"

re: fclean all
