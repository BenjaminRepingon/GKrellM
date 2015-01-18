# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:52:30 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/18 10:14:38 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	g++

CFLAGS			=	-Wall -Werror -Wextra -ansi -g

NAME			=	GKrellM

SRCS			=	$(NAME).cpp							\
					GKrellMProgram.cpp					\
					\
					Engine/CoreEngine.cpp				\
					Engine/NcursesRenderEngine.cpp		\
					Engine/GraphicRenderEngine.cpp		\
					Engine/ProgramObject.cpp			\
					Engine/Vector2f.cpp					\
					Engine/ProgramComponent.cpp			\
					Engine/Input.cpp					\
					Engine/Program.cpp					\
					Engine/GeometricDrawer.cpp			\
					\
					Modules/ModuleObject.cpp			\
					\
					Components/Hostname.cpp				\
					Components/Username.cpp				\
					Components/CurrentTime.cpp			\
					Components/Memory.cpp				\
					Components/OSInfo.cpp


 OBJS			=	$(SRCS:.cpp=.o)

INCLUDES		=	-lncurses -lSDL2 -L./sdl2/2.0.3/lib/ -I./sdl2/2.0.3/include/SDL2/

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(INCLUDES)

%.o:			%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all

install:
	brew update
	brew install sdl2
	cp -R ~/.brew/Cellar/sdl2 .

.PHONY: all, clean, fclean, re
