# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 15:35:00 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/01 18:44:28 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = pb.cpp Contact.cpp PhoneBook.cpp

TARGET = pb

$(TARGET): $(SOURCES) PhoneBook.hpp Contact.hpp Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f pb