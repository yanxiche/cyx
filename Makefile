CC = g++
SRC = *.cpp
CPPFLAGS = -g -std=c++11 -Wall
TARGET = anagram

$(TARGET):
	$(CC) $(CPPFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
