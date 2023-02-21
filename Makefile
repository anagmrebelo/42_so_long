# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 23:13:52 by anarebelo         #+#    #+#              #
#    Updated: 2023/02/21 23:50:44 by anarebelo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME			= so_long
NAME2			= so_long_bonus

# FILES
# **************************************************************************** #
SRCS		= 	gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				map/matrix.c\
				map/ft_strnjoin_2.c\
				map/read_map.c\
				imgs/imgs.c\
				imgs/imgs_player.c\
				hooks/key_hook.c\
				hooks/exit_hook.c\
				hooks/terminate_game.c\
				hooks/keycode.c\
				hooks/utils.c\
				so_long.c\
				initial_img.c
			
SRCS_BONUS	= 	gnl/get_next_line_bonus.c\
				gnl/get_next_line_utils_bonus.c\
				map/matrix_bonus.c\
				map/read_map_bonus.c\
				map/ft_strnjoin_2_bonus.c\
				imgs/imgs_bonus.c\
				imgs/imgs_player_bonus.c\
				imgs/imgs_enemy_bonus.c\
				hooks/key_hook_bonus.c\
				hooks/exit_hook_bonus.c\
				hooks/utils_bonus.c\
				hooks/keycode_bonus.c\
				hooks/terminate_game_bonus.c\
				sprites/move_enemy_bonus.c\
				sprites/animate_enemy_bonus.c\
				so_long_bonus.c\
				initial_img_bonus.c


OBJS				=${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
OBJS_BONUS			=${addprefix ${OBJS_DIR}, ${SRCS_BONUS:.c=.o}}
DEPS				=${addprefix ${OBJS_DIR}, ${SRCS:.c=.d}}
DEPS_BONUS			=${addprefix ${OBJS_DIR}, ${SRCS_BONUS:.c=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
SRCS_BONUS_DIR		= srcs_bonus/
LIBFT_DIR			= libft/

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I includes -I ${LIBFT_DIR}inc -I mlx
LIBS_EXEC			= $(LIBFT_DIR)libft.a
LIBS_EXEC			+= ./mlx/libmlx.a
LIB					= -L./mlx/ -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft


# COMPILATION
# **************************************************************************** #
LINK				= gcc
CC					= gcc -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra -Werror 
RM					= rm -rf

# RULES
# **************************************************************************** #
all:		update ${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

$(OBJS_DIR)%.o:	$(SRCS_BONUS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

${NAME}:	${OBJS} 
			${LINK} ${CFLAGS} $(INCLUDE) ${OBJS} ${LIB} -o ${NAME}

update:	
			@$(MAKE) -C ./mlx
			@$(MAKE) -C ./libft

bonus:		update ${NAME2} 

${NAME2}:	${OBJS_BONUS} 
			${LINK} ${CFLAGS} $(INCLUDE) ${OBJS_BONUS} ${LIB} -o ${NAME2}

clean:		
			@${RM} ${OBJS_DIR}
			@$(MAKE) -C ./libft clean
			@$(MAKE) -C ./mlx clean

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${NAME2}
			@$(MAKE) -C ./libft fclean
			
re:		fclean all

 -include ${DEPS}
 -include ${DEPS_BONUS}

.PHONY:		all clean fclean re bonus
