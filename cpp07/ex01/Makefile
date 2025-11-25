# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 18:00:16 by hmoukit           #+#    #+#              #
#    Updated: 2025/11/25 08:28:50 by hmoukit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.cpp iter.hpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
