# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/12/31 12:13:32 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp Bureaucrat.cpp GradeTooHighException.cpp \
			GradeTooLowException.cpp 

HEADERS = Bureaucrat.hpp GradeTooHighException.hpp \
			GradeTooLowException.hpp

TARGET = bureaucrat

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)