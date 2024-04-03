# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 20:47:05 by fsariogl          #+#    #+#              #
#    Updated: 2024/04/03 19:23:28 by fsariogl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT				=	client

NAME_SERVER				=	server

NAME_CLIENT_BONUS		=	client_bonus

NAME_SERVER_BONUS		=	server_bonus

SRC_CLIENT				=	client.c				\
							getbin.c				\
							parsing.c				\
							utils_client.c			\
							ft_atoi_client.c		\

SRC_SERVER	 			=	server.c				\
							takesig.c				\
							utils_server.c			\
							ft_atoi_server.c		\

SRC_CLIENT_BONUS		=	sigreceived.c			\
							client_bonus.c			\
							getbin_bonus.c			\
							parsing_bonus.c			\
							utils_client_bonus.c	\
							ft_atoi_client_bonus.c	\

SRC_SERVER_BONUS		=	server_bonus.c			\
							takesig_bonus.c			\
							utils_server_bonus.c	\
							ft_atoi_server_bonus.c	\

PATH_SRC				=	src/

PATH_BONUS				=	bonus/

HEADER					=	header/minitalk.h

HEADER_BONUS			=	header/minitalk_bonus.h

OBJ_CLIENT				=	$(addprefix ./src/, $(SRC_CLIENT:.c=.o))

OBJ_SERVER				=	$(addprefix ./src/, $(SRC_SERVER:.c=.o))

OBJ_CLIENT_BONUS		=	$(addprefix bonus/, $(SRC_CLIENT_BONUS:.c=.o))

OBJ_SERVER_BONUS		=	$(addprefix bonus/, $(SRC_SERVER_BONUS:.c=.o))

CFLAGS					=	-Wall -Wextra -Werror -I header

%.o				:	%.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

all						:	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)			:	$(OBJ_CLIENT) $(HEADER)
	mkdir -p ./src/obj/
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER)			:	$(OBJ_SERVER) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)
	mv ./src/*.o ./src/obj/.

bonus					:	$(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS)	:	$(OBJ_CLIENT_BONUS) $(HEADER_BONUS)
	mkdir -p ./bonus/obj/
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS)	:	$(OBJ_SERVER_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS)
	mv ./bonus/*.o ./bonus/obj/.

clean					:
	rm -rf ./src/obj ./bonus/obj

fclean					:	clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re						:	fclean all

.PHONY					:	all clean fclean re bonus