CC = gcc

CFLAGS = -I./include

LDFLAGS = -L./lib -lraylib -lgdi32 -lwinmm -O3

TARGET = backrooms.exe

SRC_DIR = ./src

SRCS := $(wildcard $(SRC_DIR)/*.c)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET)