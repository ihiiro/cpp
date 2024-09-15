# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 20:03:52 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/09/15 15:19:39 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -g

SOURCES = main.cpp return_err.cpp return_aggregate_str.cpp return_occurence_count.cpp

HEADERS = defines.hpp return_aggregate_str.hpp return_err.hpp return_occurence_count.hpp

TARGET = sed

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)