CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = src/client.c src/server.c src/utils.c
OBJDIR = obj
OBG = $(SRCS:src/%.c=$(OBJDIR)/%.o)

CLIENT = $(OBJDIR)/client.o
SERVER = $(OBJDIR)/server.o
UTILS = $(OBJDIR)/utils.o

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: client server

client: $(OBG)
	$(CC) $(FLAGS) $(UTILS) $(CLIENT) -o client

server: $(OBG)
	$(CC) $(FLAGS) $(UTILS) $(SERVER) -o server

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f client server

re: fclean all
