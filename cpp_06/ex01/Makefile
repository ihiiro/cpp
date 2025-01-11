# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2025/01/11 00:51:08 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp Serializer.cpp

HEADERS = Serializer.hpp

TARGET = reinterpret

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)