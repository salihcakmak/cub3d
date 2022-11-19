# COLORS
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m

# MESSAGE
SUCCESS		=	@echo "$(GREEN)Build successfull !$(RESET)"
RM_OBJS		=	@echo "$(RED)$(OBJS) Deleted !$(RESET)"
RM_PROGRAM	=	@echo "$(RED)Program and Library Deleted !$(RESET)"

# FILES
NAME		=	cub3D
SRCS		=	main.c all.c tdd.c
OBJS		=	$(SRCS:%.c=%.o)
DEPS		=	cub3d.h

# COMMANDS & FLAGS
CC			=	@cc
#CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-framework OpenGL -framework AppKit
OUTPUT		=	-o
RM			=	@rm -rf

#LIB
MLX_PATH	=	./minilibx
MLX_LIB		=	libmlx.a
MLX_H		=	mlx.h
THIS		=	.

# RULES
all		:	mlx $(NAME)

mlx		:
			make -C $(MLX_PATH)
			@cp $(MLX_PATH)/$(MLX_LIB) $(THIS)
			@cp $(MLX_PATH)/$(MLX_H) $(THIS)

$(NAME)	:	$(OBJS)
			@echo "\n"
			$(CC) $(OBJS)  $(MLXFLAGS) $(OUTPUT) $(NAME) $(MLX_LIB)
			$(SUCCESS)

%.o		: %.c $(DEPS)
			@printf "\033[0;30mGenerating cub3D objects... %-33.33s\r" $@
			@${CC} ${CFLAGS} -c $< -o $@

clean	:
			$(RM) $(OBJS)
			$(RM_OBJS)

fclean	:	clean
			$(RM) $(NAME) $(MLX_LIB) $(MLX_H)
			$(RM_PROGRAM)
			cd $(MLX_PATH) && make clean

re		:	fclean all


.PHONY: all mlx re clean fclean