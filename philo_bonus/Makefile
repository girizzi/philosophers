# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 11:50:00 by girizzi           #+#    #+#              #
#    Updated: 2026/03/16 16:59:40 by girizzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
CYAN	= \033[0;36m
NC		= \033[0m

NAME	= philo_bonus

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread

OBJ_DIR	= obj

SRC		= main_bonus.c \
		  init_bonus.c \
		  check_args_bonus.c \
		  utils_bonus.c \
		  simulation_bonus.c \
		  cleanup_bonus.c

OBJ		= $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)COMPILED:$(NC) $<"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(GREEN)✓ $(NAME) COMPILED!$(NC)"
	@echo ""
	@echo "$(GREEN)Run: ./philo <N1> <N2> <N3> <N4> <*N5>$(NC)"
	@echo "$(GREEN)N1:$(NC) Number of philosophers (max 300)"
	@echo "$(GREEN)N2:$(NC) Time to die"
	@echo "$(GREEN)N3:$(NC) Time to eat"
	@echo "$(GREEN)N4:$(NC) Time to sleep"
	@echo "$(GREEN)N5:$(NC) *optional Number of dinners"
	@echo ""

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)✓ OBJECTS CLEANED!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✓ $(NAME) CLEANED!$(NC)"
	@echo ""

re: fclean all

.PHONY: all clean fclean re
