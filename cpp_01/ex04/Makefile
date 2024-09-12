# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 20:03:52 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/12 05:59:46 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = sed

$(TARGET): main.cpp Makefile
	c++ main.cpp $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)