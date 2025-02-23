# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2025/02/23 04:25:01 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CFILES = main.cpp  RPN.cpp

HEADERS = RPN.hpp

NAME = RPN

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