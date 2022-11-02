CC = g++
CFLAGS = -Wall -g


TARGET          = main
SRC_MAIN        = main.cpp
SRC_PARSER		= parser.h
OBJ_MAIN 		= main.o
OBJ_PARSER 		= parser.o

# ****************************************************
# Targets needed to bring the executable up to date
 

$(TARGET): $(OBJ_MAIN) $(OBJ_PARSER)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_MAIN) $(OBJ_PARSER)
 
# The main.o target can be written more simply

$(OBJ_MAIN): $(SRC_MAIN) $(SRC_PARSER)
	$(CC) $(CFLAGS) -c $(SRC_MAIN)
 
$(OBJ_PARSER): $(SRC_PARSER)

clean:
	-rm $(TARGET) $(OBJ_MAIN) $(OBJ_PARSER)


 

 



 
