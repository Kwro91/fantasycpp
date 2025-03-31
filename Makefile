NAME = fantasy

SRC = srcs/main.cpp\
	srcs/AEntity.cpp\
	srcs/Character.cpp\
	srcs/Damage.cpp\
	srcs/fight.cpp\
	srcs/ImportSaveEntity.cpp\

	
CC =  c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

AR = ar rcs

.cpp.o:
		${CC} ${CPPFLAGS} -c $< -o ${<:.cpp=.o}

OBJ = $(SRC:.cpp=.o)

$(NAME) :	${OBJ}
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
		rm -rf $(OBJ)

fclean	:    clean
		rm -rf $(NAME)

re	:	fclean
		make