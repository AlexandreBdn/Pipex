# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:18:54 by abaudin           #+#    #+#              #
#    Updated: 2023/11/07 17:19:01 by abaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# NAME = pipex

# SRCS = pipex.c\
# 	utils/ft_putchar_fd.c\
# 	utils/ft_split.c\
# 	utils/ft_strjoin.c\
# 	utils/utils.c\


# AR = ar rcs

# OBJS =	${SRCS:.c=.o}

# CFLAGS= -Wall -Wextra -Werror -g3 #-fsanitize=address

# CC = cc

# .c.o:
# 			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


# ${NAME} : ${OBJS}
# 	$(AR) $(NAME) ${OBJS} 	

# all : ${NAME}


# #compile: $(OBJS)
# #		$(CC) $(CFLAGS) -o a.out $(OBJS)

# clean:
# 	rm -f ${OBJS}

# fclean :clean
# 	rm -f ${NAME}

# re: fclean all

NAME = pipex

FICHIERS_C = pipex.c\
	utils/ft_putchar_fd.c\
 	utils/ft_split.c\
 	utils/ft_strjoin.c\
 	utils/utils.c\
             

OBJS = $(patsubst %.c,%.o,$(FICHIERS_C))

CFLAGS= -Wall -Werror -Wextra -g3

CC = cc
${NAME} : ${OBJS} 
	$(CC) $(CFLAGS) ${OBJS} -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
.SILENT: