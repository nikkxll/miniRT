# MINI_RT_PROJECT_MAKEFILE
include libft/.make

NAME			:=	miniRT

CC				:=	cc
CFLAGS			:=	-g -Wall -Wextra -Werror

# SOURCE_FILES
SRCS			:=	main.c
SRCS_PATH		:=	srcs/

# OBJECT_FILES
OBJS_PATH		:=	objs/
OBJS			:=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

# LIBFT_LIBRARY
LIBFT_PATH		:=	$(LIBFT_PATH)
LIBFT_SOURSES	:=	$(addprefix $(LIBFT_PATH), $(LIBFT_SOURSES))
LIBFT			:=	$(addprefix $(LIBFT_PATH), $(LIBFT))

# HEADERS AND EXTERNAL LIBRARIES
HEADERS			:=	$(LIBFT_PATH)libft.h
INCLUDES		:=	$(addprefix -I , $(HEADERS))
LIBMLX			:=	./lib/MLX42
MLX				:=	./lib/MLX42/build/libmlx42.a
LIBMLX_DIR		:=	$(LIBMLX)/include

# MLX FOR SCHOOL COMPUTERS 
LIBS			:=	-lft -L $(LIBFT_PATH) -L$(LIBMLX)/build -lmlx42 -L"/opt/homebrew/opt/glfw/lib/" \
					-lglfw -framework OpenGL -framework AppKit

# MLX FOR MacOS (M1 and later)
# LIBS			:=	-lft -L $(LIBFT_PATH) -L$(LIBMLX)/build -lmlx42 -L"~/.brew/opt/glfw/lib" \
# 					-lglfw -framework OpenGL -framework AppKit

# LOADING PROGRESS BAR INIT
TOTAL_OBJS		:=	$(words $(OBJS))
COMPILED_OBJS	:=	0
MSG_PRINTED 	:=	false

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS) $(HEADERS)
	@cc $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)\n\n$(NAME) created successfully!$(EC)"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(call progress,"miniRT")

$(LIBFT): $(LIBFT_SOURSES)
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@echo "$(CYAN)\nMLX preparations\n$(EC)"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(GREEN)\nLibrary 'libmlx42.a' created$(EC)"

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@rm -rf $(LIBMLX)/build
	@echo "$(RED)*.o files removed!$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(RED)\nFull clean up completed successfully!$(EC)"

re: fclean all

.PHONY: all clean fclean re