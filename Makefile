# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 21:02:16 by mtomomit          #+#    #+#              #
#    Updated: 2022/09/01 12:20:22 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
NAME_BONUS	= fdf_bonus
MLX			= libmlx_Linux.a
LIBFT		= libft.a
FDF			= ./incs/fdf.a
FDF_BONUS	= ./incs/fdf_bonus.a

MLX_PATH	= ./minilibx_linux/
LIBFT_PATH  = $(FDF_PATH)/libft
FDF_PATH	= $(shell pwd)

SRC 		= ./srcs/main.c \
				./srcs/bresenham.c \
				./srcs/isometric.c \
				./srcs/keyhandle.c \
				./srcs/close.c \
				./srcs/error.c \
				./srcs/read.c \
				./srcs/connect.c \
				./srcs/draw.c \
				./srcs/transformation.c \
				./srcs/convert.c \

OBJS = ${SRC:.c=.o}

SRC_BONUS 	= ./srcs_bonus/main_bonus.c \
				./srcs_bonus/bresenham_bonus.c \
				./srcs_bonus/isometric_bonus.c \
				./srcs_bonus/keyhandle_bonus.c \
				./srcs_bonus/close_bonus.c \
				./srcs_bonus/error_bonus.c \
				./srcs_bonus/read_bonus.c \
				./srcs_bonus/connect_bonus.c \
				./srcs_bonus/draw_bonus.c \
				./srcs_bonus/transformation_bonus.c \
				./srcs_bonus/convert_bonus.c \
				./srcs_bonus/clear_bonus.c	\
				./srcs_bonus/change_scale_bonus.c \
				./srcs_bonus/change_z_bonus.c \
				./srcs_bonus/reset_bonus.c \
				./srcs_bonus/rotate_x_bonus.c \
				./srcs_bonus/rotate_y_bonus.c \
				./srcs_bonus/rotate_z_bonus.c \
				./srcs_bonus/change_axis_bonus.c \
				./srcs_bonus/translation_x_bonus.c \
				./srcs_bonus/translation_y_bonus.c \

OBJS_BONUS = ${SRC_BONUS:.c=.o}

HEADER = ./incs/fdf.h
HEADER_BONUS = ./incs/fdf_bonus.h

LIB_FLAGS = ar -rcs

CC			= cc -Wall -Wextra -Werror
MLX_CF		= -lm -lbsd -lmlx -lXext -lX11

.c.o:
			${CC} -I/libft -I/incs -I/minilibx_linux -c $< -o ${<:.c=.o}

all: $(NAME)

$(FDF):	$(OBJS) $(HEADER)
		$(LIB_FLAGS) $(FDF) $(OBJS)

$(NAME): $(OBJS) $(HEADER) $(FDF)
		make -C $(MLX_PATH)
		make -C $(LIBFT_PATH)
		$(CC) -o $(NAME) $(FDF) $(LIBFT_PATH)/$(LIBFT) -g -L$(MLX_PATH) $(MLX_CF)

clean:
	rm -f $(OBJS)
	rm -f ./libft/$(LIBFT)
	rm -f $(FDF)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean:	clean
	rm -f $(NAME)

bonus: $(NAME_BONUS)

$(FDF_BONUS): $(OBJS_BONUS) $(HEADER_BONUS)
		$(LIB_FLAGS) $(FDF_BONUS) $(OBJS_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(FDF_BONUS) $(HEADER_BONUS)
		make -C $(MLX_PATH)
		make -C $(LIBFT_PATH)
		$(CC) -o $(NAME_BONUS) $(FDF_BONUS) $(LIBFT_PATH)/$(LIBFT) -g -L$(MLX_PATH) $(MLX_CF)

clean_bonus:
	rm -f ./libft/$(LIBFT)
	rm -f $(OBJS_BONUS)
	rm -f $(FDF_BONUS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean_bonus: clean_bonus
		rm -f $(NAME_BONUS)

re: fclean all

rebonus: fclean_bonus bonus

run: all
	./fdf test_maps/42.fdf

runb: bonus
	./fdf_bonus test_maps/42.fdf

n:
	norminette $(SRC) $(HEADER)

nb:
	norminette $(SRC_BONUS) $(HEADER_BONUS)

runl: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf test_maps/42.fdf

runbl: bonus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf_bonus test_maps/42.fdf
