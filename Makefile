CC = gcc

CFLAGS = -I./include

LDFLAGS = -L./lib -lraylib -lgdi32 -lwinmm -O3

TARGET = backrooms.exe

SRC = ./src/main.c

$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET)