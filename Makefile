TARGET           = parser.exe
SOURCE_01        = main.cpp

$(TARGET):	$(SOURCE_01)
	g++ -g -o $(TARGET) $(SOURCE_01)

clean:
	-rm $(TARGET)

