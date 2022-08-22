# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 15:36:23 by ple-stra          #+#    #+#              #
#    Updated: 2022/08/22 06:45:04 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_C		= checker

SRCS_DIR	= srcs
SRCS_SHA	= \
 debug.c errors.c free.c\
 push.c rotate.c swap.c\
 num_utils.c\
 init.c parsing.c
SRCS_P_DIR	= srcs_push_swap
SRCS_PUSH	= push_swap.c\
 sort_stack.c\
 find_median.c divide_stacks.c stack_arr_utils.c\
 rotation_utils.c rotation_optimization.c
SRCS_C_DIR	= srcs_checker
SRCS_CHECK	= checker_bonus.c\
 exec_instructions_bonus.c
BUILD_DIR	= build
OBJ_SHA_DIR	= $(BUILD_DIR)/objs_shared
OBJ_P_DIR	= $(BUILD_DIR)/objs_push_swap
OBJ_C_DIR	= $(BUILD_DIR)/objs_checker
OBJ_SHA		= $(addprefix $(OBJ_SHA_DIR)/, $(SRCS_SHA:.c=.o))
OBJ_PUSH	= $(addprefix $(OBJ_P_DIR)/, $(SRCS_PUSH:.c=.o))
OBJ_CHECK	= $(addprefix $(OBJ_C_DIR)/, $(SRCS_CHECK:.c=.o))
INC			= -I./includes -I./$(LIBFT_DIR)/includes
INC_PUSH	= -I./includes_push_swap
INC_CHECK	= -I./includes_checker

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/build/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR)/build -lft

CC			= cc
CFLAGS		= -Wall -Wextra
LFLAGS		= $(LIBFT_FLAGS)
ifneq (nWerror, $(filter nWerror,$(MAKECMDGOALS)))
	CFLAGS	+= -Werror
endif
ifeq (sanitize, $(filter sanitize,$(MAKECMDGOALS)))
	CFLAGS 	+= -fsanitize=address
endif
ifeq (debug, $(filter debug,$(MAKECMDGOALS)))
	CFLAGS	+= -D KDEBUG=1
endif

GIT_SUBM	= $(shell \
 sed -nE 's/path = +(.+)/\1\/.git/ p' .gitmodules | paste -s -)
RM			= rm -rf

all			: $(NAME)

bonus		: $(NAME_C)

both		: $(NAME) $(NAME_C)

$(OBJ_SHA_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_SHA_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
$(OBJ_P_DIR)/%.o: $(SRCS_P_DIR)/%.c
	@mkdir -p $(OBJ_P_DIR)
	$(CC) $(CFLAGS) $(INC) $(INC_PUSH) -c $< -o $@
$(OBJ_C_DIR)/%.o: $(SRCS_C_DIR)/%.c
	@mkdir -p $(OBJ_C_DIR)
	$(CC) $(CFLAGS) $(INC) $(INC_CHECK) -c $< -o $@

$(GIT_SUBM): %/.git: .gitmodules
	@git submodule update --init $*

$(LIBFT)	:
ifeq (,$(wildcard $(LIBFT)))
			@echo "building libft..."
			@$(MAKE) -sC $(LIBFT_DIR) all
endif

rmlibft		:
			@echo "deleting libft build..."
			@$(MAKE) -sC $(LIBFT_DIR) fclean

$(NAME)		: $(GIT_SUBM) $(LIBFT) $(OBJ_SHA) $(OBJ_PUSH)
			$(CC) $(CFLAGS) $(INC) $(INC_PUSH) -o $(NAME) $(OBJ_SHA) $(OBJ_PUSH) $(LFLAGS)

$(NAME_C)	: $(GIT_SUBM) $(LIBFT) $(OBJ_SHA) $(OBJ_CHECK)
			$(CC) $(CFLAGS) $(INC) $(INC_CHECK) -o $(NAME_C) $(OBJ_SHA) $(OBJ_CHECK) $(LFLAGS)

clean		:
			$(RM) $(OBJ_SHA_DIR)
			$(RM) $(OBJ_P_DIR)
			$(RM) $(OBJ_C_DIR)

fclean_p	:
			$(RM) $(OBJ_SHA_DIR)
			$(RM) $(OBJ_P_DIR)
			$(RM) $(NAME_P)

fclean_c	:
			$(RM) $(OBJ_SHA_DIR)
			$(RM) $(OBJ_C_DIR)
			$(RM) $(NAME_C)

fclean		:
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)
			$(RM) $(NAME_C)

fcleanall	: rmlibft
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)
			$(RM) $(NAME_C)

re			: fclean_p all 

rebonus		: fclean_c bonus

nWerror		:
			@echo "WARN: Compiling without Werror flag!"
sanitize	:
			@echo "WARN: Compiling with fsanitize flag!"
debug:
			@echo "WARN: debug is enabled"

.PHONY: \
 all bonus both clean fclean_p fclean_c fclean fcleanall re rebonus rmlibft\
 nWerror sanitize debug