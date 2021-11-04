HEADERS = $(shell ls *.h)
SOURCES = $(shell ls *.cpp)

CFLAGS = -W -Wall -std=c++17
DEBUGFLAGS = -g
CXX = g++

LFLAGS =
LIBS =

INCLUDES = -I.

OBJS = $(SOURCES:.cpp=.o)

BINARY = main

all: $(BINARY)

$(BINARY): $(OBJS)
	$(CXX) -o $@ $^ $(LFLAGS) $(LIBS)

depend:
	makedepend -f- -- $(SOURCES) > .depend_file
clean:
	$(RM) $(BINARY)
	$(RM) $(OBJS) 

#DO NOT DELETE