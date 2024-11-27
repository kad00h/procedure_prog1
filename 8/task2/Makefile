CC = gcc
CFLAGS = -g -Wall -std=c11

# Список об'єктних файлів
OBJS = c_list.o test_c_list.o

# Ціль за замовчуванням
all: test_c_list

# Компіляція виконавчого файлу
test_c_list: $(OBJS)
	$(CC) $(CFLAGS) -o test_c_list $(OBJS)

# Компіляція окремих об'єктних файлів
c_list.o: c_list.c c_list.h
	$(CC) $(CFLAGS) -c c_list.c

test_c_list.o: test_c_list.c c_list.h
	$(CC) $(CFLAGS) -c test_c_list.c

# Очистка
clean:
	rm -f *.o test_c_list
