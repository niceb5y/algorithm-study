CC = gcc
OBJS = ../util/util.c
TARGET = run.out

.SUFFIXES : .c .o

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) -o $@ $(OBJS) solve.c

clean: 
		rm -f $(TARGET)
		