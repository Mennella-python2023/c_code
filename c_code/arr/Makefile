
# Nome dell'eseguibile
EXEC = programma

# File sorgenti
SRCS = main.c funzioni.c

# Compilatore
CC = gcc

# Opzioni
CFLAGS = -Wall -Wextra -std=c11

# Regola principale
all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

# Pulizia
clean:
	rm -f $(EXEC)
