# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:20:38 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/12/15 00:41:38 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SOURCES = main.cpp AMateria.cpp Cure.cpp ICharacter.cpp IMateriaSource.cpp \
			Ice.cpp MateriaSource.cpp Character.cpp

HEADERS = AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp \
			IMateriaSource.hpp Ice.hpp MateriaSource.hpp

TARGET = interface

$(TARGET): $(SOURCES) $(HEADERS) Makefile
	c++ $(SOURCES) $(CFLAGS) -o $@

clear:
	rm -f $(TARGET)