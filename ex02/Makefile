# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 13:43:13 by abechcha          #+#    #+#              #
#    Updated: 2024/12/13 13:43:43 by abechcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	  PmergeMe.cpp\

OBJ = $(SRC:.cpp=.o)
NAME = PmergeMe
HEDER = PmergeMe.hpp
CFLAGS =  -Wall -Wextra -Werror -std=c++98

all : $(NAME)

%.o : %.cpp ${HEDER} Makefile
	c++ ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJ) ${HEDER}
	 c++ ${CFLAGS} $(OBJ) -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean