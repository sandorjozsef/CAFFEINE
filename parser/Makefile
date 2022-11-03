CC = g++
CFLAGS = -Wall -g

parser.exe: main.cpp parser.hpp parser.cpp parsable.hpp caff_block.hpp caff_block.cpp caff.hpp caff_header.hpp caff_header.cpp caff_credits.hpp caff_credits.cpp caff_animation.hpp caff_animation.cpp
	$(CC) $(CFLAGS) $? -o $@


clean:
	-rm parser.exe