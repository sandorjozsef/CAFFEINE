CC = g++
CFLAGS = -Wall -g

parser.exe: main.cpp parser.hpp parser.cpp parsable.hpp caff_block.hpp caff.hpp
	$(CC) $(CFLAGS) $? -o $@


clean:
	-rm parser.exe