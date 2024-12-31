# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/12/31 19:26:47 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp Bureaucrat.cpp GradeTooHighException.cpp \
			GradeTooLowException.cpp Form.cpp FormLowException.cpp \
			FormHighException.cpp

HEADERS = Bureaucrat.hpp GradeTooHighException.hpp \
			GradeTooLowException.hpp Form.hpp \
			FormLowException.hpp FormHighException.hpp

TARGET = bureaucrat

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)