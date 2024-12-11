# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 12:51:16 by abechcha          #+#    #+#              #
#    Updated: 2024/12/10 12:52:14 by abechcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	  BitcoinExchange.cpp\

OBJ = $(SRC:.cpp=.o)
NAME = btc
HEDER = BitcoinExchange.hpp
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