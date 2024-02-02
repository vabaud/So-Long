NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= MLX42

SRC 	:= inc/so_long.h \

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./src
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:=	src/test.c \
			src/maps.c \
			src/get_next_line_utils.c \
			src/get_next_line.c \
			src/mouv_perso.c \
			src/mouv_barrel.c \
			src/mapValid.c \
			#end.c 

# Ajoutez le chemin vers le dossier build ici
OBJS	:= $(patsubst %.c,build/%.o,$(SRCS))
INCLUDE = -I src

all:	libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Modifiez la règle de compilation pour placer les fichiers .o dans le dossier build
build/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf build
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx