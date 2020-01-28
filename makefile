# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2020/01/28 10:42:53 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###

CC = gcc -Wall -Werror -Wextra

CFLAGS = -g3 -fsanitize=address
# -Wall -Werror -Wextra
MLXFLAGS = -framework OpenGL -framework AppKit

### EXECUTABLE ###

NAME = wolf3d

### INCLUDES ###

SRC_NAME = main.c ft_parse_map.c ft_parse_map2.c read_param.c mlx_img.c\
			display_column.c check_texture.c key_hook.c \
			calcul_ray.c print_texture.c dda.c
SRC_PATH = srcs
OBJ_PATH = objs
HEADER = incl
LIBFT = libft
LIBMLX = minilibx_macos

### OBJECTS ###

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))


### COLORS ###

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: tmp $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	@echo "$(GREEN)Project compiling ...$(NOC)"
	@$(CC) $(CFLAGS) -L $(LIBFT) -o $@ $^ $(MLXFLAGS) -L $(LIBMLX) minilibx_macos/libmlx.a libft/libft.a
	@echo "$(GREEN)Project successfully compiled !$(NOC)"

tmp:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(CFLAGS) -I $(HEADER) -c -o $@ $<


clean:
	@echo "$(RED)Supressing ...$(NOC)"
	@make clean -C $(LIBFT)
	@make clean -C $(LIBMLX)
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Object files suppressed$(NOC)"

fclean:
	@echo "$(RED)Supressing ...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(LIBMLX)
	@echo "$(RED)Files suppressed$(NOC)"

re: fclean all

.phony: all, tmp, re, fclean, clean