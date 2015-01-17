# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:52:30 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/17 18:44:10 by dsousa           ###   ########.fr        #
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
					Components/Username.cpp

OBJS			=	$(SRCS:.cpp=.o)

INCLUDES		=	-lncurses


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


.PHONY: all, clean, fclean, re
