CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = src/client.c src/server.c src/utils.c
OBG = $(SRCS:%.c=$(OBJDIR)/%.o)

OBJDIR = obj
CLIENT = $(OBJDIR)/client.o
SERVER = $(OBJDIR)/server.o

all: $(OBJDIR) client server

	$(OBJDIR): $(OBG)
		mkdir $(OBJDIR)

	$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
		$(CC) $(FLAGS) -c $< -o $@


	client: $(OBG)
		$(CC) $(FLAGS) $(CLIENT) -o client

	server: $(OBG)
		$(CC) $(FLAGS) $(SERVER) -o server