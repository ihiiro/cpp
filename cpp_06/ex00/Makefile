# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2025/01/10 18:45:13 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp ScalarConverter.cpp

HEADERS = ScalarConverter.hpp

TARGET = static

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)