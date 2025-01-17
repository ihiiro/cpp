# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2025/01/17 11:34:45 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CFILES = main.cpp ScalarConverter.cpp

HEADERS = ScalarConverter.hpp

NAME = static

OFILES = $(CFILES:.cpp=.o)

%.o: %.cpp
	c++ $(CFLAGS) -c $<

$(NAME): $(OFILES) $(HEADERS) Makefile
	c++ $(OFILES) -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all