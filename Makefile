NAME					=					gravity_balls


SRC						=					src/gravity_balls.c				\
											src/game.c						\
											src/ball.c						\
											src/color.c

OBJ						=					$(SRC:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network

CFLAGS					=					-I include/ $(LIB)

all:					$(NAME)
$(NAME):				$(OBJ)
						gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean:
						$(RM) -rf $(OBJ)
fclean:					clean
						$(RM) -rf $(NAME)
re:						fclean all