SRCS		= 	src/gnl/get_next_line.c\
			src/gnl/get_next_line_utils.c\
			src/map/matrix.c\
			src/map/ft_strnjoin_2.c\
			src/map/read_map.c\
			src/imgs/imgs.c\
			src/imgs/imgs_player.c\
			src/hooks/key_hook.c\
			src/hooks/exit_hook.c\
			src/hooks/terminate_game.c\
			src/hooks/keycode.c\
			src/hooks/utils.c\
			src/so_long.c\
			src/initial_img.c
			
SRCS_BONUS	= 	src_bonus/gnl/get_next_line_bonus.c\
			src_bonus/gnl/get_next_line_utils_bonus.c\
			src_bonus/map/matrix_bonus.c\
			src_bonus/map/read_map_bonus.c\
			src_bonus/map/ft_strnjoin_2_bonus.c\
			src_bonus/imgs/imgs_bonus.c\
			src_bonus/imgs/imgs_player_bonus.c\
			src_bonus/imgs/imgs_enemy_bonus.c\
			src_bonus/hooks/key_hook_bonus.c\
			src_bonus/hooks/exit_hook_bonus.c\
			src_bonus/hooks/utils_bonus.c\
			src_bonus/hooks/keycode_bonus.c\
			src_bonus/hooks/terminate_game_bonus.c\
			src_bonus/sprites/move_enemy_bonus.c\
			src_bonus/sprites/animate_enemy_bonus.c\
			src_bonus/so_long_bonus.c\
			src_bonus/initial_img_bonus.c


OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

NAME			= so_long
NAME2			= .filetrack
HEADER			= includes/so_long.h
HEADER_BONUS	= includes/so_long_bonus.h

LIB				= -L./mlx/ -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft
LIB_PATH		= ./mlx/libmlx.a
LIB_PATH2		= ./libft/libft.a

.c.o:
		${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

all:		update ${NAME}

${NAME}:	${OBJS} ${HEADER}
			@${RM} ${OBJS_BONUS}
			${CC} ${CFLAGS} -I./mlx -I./libft ${SRCS} ${LIB} -o ${NAME}

update:	
			@$(MAKE) -C ./mlx
			@$(MAKE) -C ./libft

bonus:		update ${NAME2} 

${NAME2}:	${OBJS_BONUS} ${HEADER_BONUS} ${LIBPATH} ${LIBPATH2}
			@${RM} ${OBJS}
			${CC} ${CFLAGS} ${SRCS_BONUS} ${LIB} -o ${NAME}
			@touch $@

clean:		
		@${RM} ${OBJS}
		@${RM} ${OBJS_BONUS}
		@$(MAKE) -C ./libft clean
		@$(MAKE) -C ./mlx clean

fclean:		clean
		${RM} ${NAME}
		@${RM} ./libmlx.a
		@${RM} ${LIB_PATH}
		@${RM} ${NAME2}
		@$(MAKE) -C ./libft fclean

re:		fclean all

.PHONY:		all clean fclean re bonus
