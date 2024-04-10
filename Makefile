NAME		:= so_long
CFLAGS		+= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:= MLX42
LIBFT_DIR	= libft/
LIBFT		= $(LIBFT_DIR)libft.a

SRC 	:= inc/so_long.h

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./src
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:=	src/main.c \
			src/maps.c \
			src/mouv_perso.c \
			src/mouv_barrel.c \
			src/mapValid.c \
			src/exit.c \

OBJS	:= $(patsubst %.c,build/%.o,$(SRCS))
DEPS	:= $(OBJS:.o=.d)
INCLUDE = -I src

all:	libmlx $(LIBFT) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

build/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf build
	@rm -rf $(LIBMLX)/build
	make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all, clean, fclean, re, libmlx