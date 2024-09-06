# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 16:17:33 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/06 16:19:22 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = zombie

SOURCES = main.cpp Zombie.cpp ZombieHorde.cpp

$(TARGET): $(SOURCES) Makefile Zombie.hpp
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f zombie