# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 21:48:04 by aabduvak          #+#    #+#              #
#    Updated: 2022/01/30 21:48:04 by aabduvak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)

NAME	= datastc.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror


all : ${NAME}

$(NAME) : ${OBJS} 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette *.[ch]

re : fclean all


help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make        --------- will compile all *.c files and create libft.a library"
	@echo "make clean  --------- will clean all *.o files in sources"
	@echo "make fclean --------- will clean all *.o files in sources and libft.a library"
	@echo "make re     --------- will clean all files and compiles again"

.PHONY: all clean fclean re .c.o