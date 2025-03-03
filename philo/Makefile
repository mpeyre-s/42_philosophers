# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 13:47:18 by mathispeyre       #+#    #+#              #
#    Updated: 2025/03/03 13:47:20 by mathispeyre      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
OBJDIR		= objects/

CC			= gcc
CFLAGS		= -Werror -Wextra -Wall

SRC			= philosophers.c errors.c init_and_parse.c time.c utils.c
OBJ			= $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(NAME) ready"

clean:
	@echo "Removing object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
