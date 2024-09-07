# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 17:47:05 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/07 17:54:25 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = uv

SOURCES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

$(TARGET): $(SOURCES) Makefile
	c++ main.cpp $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)