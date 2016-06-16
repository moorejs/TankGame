CC = g++
CXXFLAGS = -Wall -std=c++14 -I/usr/local/Cellar/sfml/2.3_1/include
LDLIBS = -L/usr/local/Cellar/sfml/2.3_1/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

EXEC = output
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LDLIBS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -f $(EXEC) $(OBJECTS)
