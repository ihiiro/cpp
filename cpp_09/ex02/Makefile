# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2025/03/01 04:34:18 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CFILES = main.cpp

HEADERS = PmergeMe.hpp

NAME = PmergeMe

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