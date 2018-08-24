##
## Makefile for raytracer in /home/Yadaro/raytracer1
## 
## Made by Yadaro YUN
## Login   <yadaro.yun@epitech.net>
## 
## Started on  Mon Nov 28 15:49:54 2016 Yadaro YUN
## Last update Wed Mar 22 16:15:26 2017 Yadaro YUN
##

CC	=	gcc

RM	=	rm -f

NAME	=	raytracer1

CFLAGS	+=	-Iinclude -Wextra -Wall -W -Werror


SRC	=	main.c			\
		src/sphere.c		\
		src/calc_dir_vector.c	\
		src/plane.c		\
		pixel.c			\
		src/cylinder.c		\
		src/light.c		\
		src/cone.c		\
		color.c	
OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC)  $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
