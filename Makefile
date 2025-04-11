CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = src/client.c src/server.c src/utils.c
OBJDIR = obj
OBG = $(SRCS:src/%.c=$(OBJDIR)/%.o)

CLIENT = $(OBJDIR)/client.o
SERVER = $(OBJDIR)/server.o
UTILS = $(OBJDIR)/utils.o


all: client server

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

client: $(OBG)
	$(CC) $(FLAGS) -o client $(UTILS) $(CLIENT) 

server: $(OBG)
	$(CC) $(FLAGS) -o server $(UTILS) $(SERVER) 

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: clean

.SECANDRY: $(OBJDIR)