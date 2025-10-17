CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = my_tool
SOURCES = main.c cat.c write.c stats.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: clean