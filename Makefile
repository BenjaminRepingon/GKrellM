# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:52:30 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/18 18:10:08 by dsousa           ###   ########.fr        #
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
					\
					Modules/ModuleObject.cpp			\
					\
					Components/Hostname.cpp				\
					Components/Username.cpp				\
					Components/CurrentTime.cpp			\
					Components/Memory.cpp				\
					Components/MemoryGraphic.cpp		\
					Components/OSInfo.cpp				\
					Components/Cpu.cpp


OBJS			=	$(SRCS:.cpp=.o)

INCLUDES		=

LIBS			=	-lncurses

all:			$(NAME)

$(NAME):		generate $(OBJS)
	@printf "Compiling objects"
	@$(CC) -o $(NAME) $(OBJS) $(LIBS)

generate:
	@printf "Generate objects: \n"

%.o:			%.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@echo $@

clean:
	@printf "Remove objects\n"
	@rm -rf $(OBJS)

fclean:			clean
	@printf "Remove binary\n"
	@rm -rf $(NAME)

re:				fclean all

install:
	brew update
	brew install sdl2
	cp -R ~/.brew/Cellar/sdl2 .

.PHONY: all, clean, fclean, re
