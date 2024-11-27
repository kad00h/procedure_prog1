CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = main.exe

SRCS = main.c c_list.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /q /f $(OBJS) $(TARGET)
