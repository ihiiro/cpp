# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 18:20:21 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/02 19:54:01 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = tests.cpp Account.cpp

TARGET = banker

$(TARGET): $(SOURCES) Account.hpp Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f banker