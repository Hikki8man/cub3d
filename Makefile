NAME =	cub3D
LIBDIR =   libft/
MLX = minilibx
SRCSF =	main.c \
		ft_action.c \
		ft_action2.c \
		ft_draw_frame.c \
		ft_draw_hud.c \
		ft_enemy_lst_func.c \
		ft_free.c \
		ft_free2.c \
		ft_get_settings.c \
		ft_hud.c \
		ft_init_images.c \
		ft_init_struct.c \
		ft_key_event.c \
		ft_key_event2.c \
		ft_mouvement.c \
		ft_mouvement2.c \
		ft_parsing.c \
		ft_parsing_first_rd.c \
		ft_parsing_second_rd.c \
		ft_raycast.c \
		ft_raycast2.c \
		ft_set.c \
		ft_sprite.c \
		ft_sprite_lst_func.c \
		ft_utils.c \
		ft_utils2.c \
		ft_wall.c \
		ft_main_args.c \
		ft_img_to_bmp.c \
		ft_minimap.c \
		ft_exit.c
SRCS =	$(addprefix srcs/, ${SRCSF})
INDIR = includes
CC = 	gcc
CFLAGS = -Wall -Wextra -Werror -O3
OBJS =  ${SRCS:.c=.o}

all		:	${NAME}

srcs/%.o : srcs/%.c ${INDIR} libft/libft.h
			${CC} ${CFLAGS} -c $< -o $@ -I ${INDIR}

${NAME}: ${OBJS}
			make -C ${LIBDIR}
			make -C ${MLX}
			${CC} -L ${MLX} -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} libft/libft.a ${MLX}/libmlx.a

run		:	${NAME}
			./${NAME} map.cub

libft	:
			make -C ${LIBDIR}
clean	:
			make clean -C ${LIBDIR}
			make clean -C ${MLX}
			rm -f ${OBJS}

fclean	:	clean
			make fclean -C ${LIBDIR}
			make clean -C ${MLX}
			rm -f ${NAME}

re		:	fclean ${NAME}

.PHONY	:	re clean fclean libft .c.o