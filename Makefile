#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

#resource
SRCS = 
OBJECTS = $(SRCS:.c=.o)
LIBFT = libft.a
NAME = Minitalk

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUSOBJECT)
	@ar rcs $(NAME)  $(BONUSOBJECT)

clean :
	@rm -rf $(OBJECTS) $(BONUSOBJECT)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean clean bonus

.SECONDARY: $(OBJECTS)
