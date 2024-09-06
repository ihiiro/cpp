# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 15:35:58 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/06 16:10:51 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = zombie

SOURCES = main.cpp zombie.cpp randomChump.cpp newZombie.cpp

$(TARGET): $(SOURCES) Makefile Zombie.hpp
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f zombie