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
NAME		=	dev
SRCS		=	source/main.c source/all.c source/utils_base.c source/utils_file.c source/utils_init_check.c source/utils_string.c source/init.c
OBJS		=	$(SRCS:%.c=%.o)
DEPS		=	cube.h

# COMMANDS & FLAGS
CC			=	@gcc
#CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-framework OpenGL -framework AppKit
OUTPUT		=	-o
RM			=	@rm -rf

#LIB
MLX_PATH	=	./minilibx
MLX_LIB		=	libmlx.a
MLX_H		=	mlx.h
THIS		=	source/


#LIB
LIBFT_PATH	=	./libft
LIBFT_LIB	=	libft.a
LIBFT_H		=	libft.h


# RULES
all		:	libft mlx $(NAME)

libft	:
			make -C $(LIBFT_PATH)
			@cp $(LIBFT_PATH)/$(LIBFT_LIB) $(THIS)
			@cp $(LIBFT_PATH)/$(LIBFT_H) header/

mlx		:
			make -C $(MLX_PATH)
			@cp $(MLX_PATH)/$(MLX_LIB) $(THIS)
			@cp $(MLX_PATH)/$(MLX_H) header/

$(NAME)	:	$(OBJS)
			@echo "\n"
			$(CC) $(OBJS)  $(MLXFLAGS) $(OUTPUT) $(NAME) ./source/$(MLX_LIB) ./source/$(LIBFT_LIB)
			$(SUCCESS)

%.o		: %.c $(DEPS)
			@printf "\033[0;35mGenerating cub3D objects... %-33.33s\r" $@
			@${CC} ${CFLAGS} -c $< -o $@

clean	:
			$(RM) $(OBJS)
			$(RM_OBJS)

fclean	:	clean
			$(RM) $(NAME) ./source/$(MLX_LIB) header/$(MLX_H) ./source/$(LIBFT_LIB) header/$(LIBFT_H)
			$(RM_PROGRAM)
			cd $(MLX_PATH) && make clean
			cd $(LIBFT_PATH) && make fclean

re		:	fclean all


.PHONY: all mlx re clean fclean libft