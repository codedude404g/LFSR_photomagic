CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
TARGET = FibLFSR.o PhotoMagic.o
all: PhotoMagic
FibLFSR.o: FibLFSR.cpp
	$(CC) $(CFLAGS) -o $@ $<
PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -o $@ $<
PhotoMagic: FibLFSR.o PhotoMagic.o
	g++ $? -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system -o $@
clean:
	rm $(TARGET)
