# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/16 15:52:17 by faneyer      #+#   ##    ##    #+#        #
#    Updated: 2019/01/31 15:38:47 by pitirard    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME 	= 	fillit

CC 		= 	gcc
CFLAGS 	+= 	-Wall -Wextra -Werror

SRC 	= 	ft_read.c\
			ft_checkerror.c\
			ft_create_elem.c\
			ft_push_back_list.c\
			fill_tab.c\
			ft_back.c\
			ft_switch.c\
			main.c

INCS =	./fillit.h\
		./libft/libft.h

OBJ = $(SRC:.c=.o) 

all: $(NAME) $(INCS)

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) ./libft/libft.a

lib:
	( cd ./libft && make && cd ..)

lib_clean:
	(cd ./libft && make clean && cd ..)

lib_fclean:
	(cd ./libft && make fclean && cd ..)

clean: lib_clean
	rm -rf $(OBJ)

fclean: clean lib_fclean
	rm -rf $(NAME)

re: fclean all
