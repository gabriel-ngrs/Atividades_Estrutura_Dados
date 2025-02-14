CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = lista

all: $(TARGET)

$(TARGET): lista.c
	$(CC) $(CFLAGS) lista.c -o $(TARGET)

clean:
	rm -f $(TARGET)
