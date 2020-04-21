CXX = g++
CXXFLAGS = -std=c++0x -g -O3 -w -Wall  $(shell sdl2-config --cflags) 
LDFLAGS = $(shell sdl2-config --libs) 
OBJECTS = main.o
TARGET = hellosdl

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)  $(LDFLAGS)

main.o :

clean:
	rm -rf $(OBJECTS) $(TARGET)

remake:
	clean $(TARGET)

