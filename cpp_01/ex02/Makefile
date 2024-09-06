# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 16:53:26 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/06 16:54:37 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = brain

$(TARGET): main.cpp Makefile
	c++ main.cpp $(CFLAGS) -o $@

clear:
	rm -f brain