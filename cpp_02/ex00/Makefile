# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:08:27 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/11/14 17:10:13 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp Fixed.cpp

HEADERS = Fixed.hpp

TARGET = fixed

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)