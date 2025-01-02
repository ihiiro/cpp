# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2025/01/02 18:18:08 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp Bureaucrat.cpp GradeTooHighException.cpp \
			GradeTooLowException.cpp AForm.cpp FormLowException.cpp \
			FormHighException.cpp PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp

HEADERS = Bureaucrat.hpp GradeTooHighException.hpp \
			GradeTooLowException.hpp AForm.hpp \
			FormLowException.hpp FormHighException.hpp \
			ShrubberyCreationForm.hpp PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp

TARGET = forms

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)