CC=g++
CFLAGS= -c -I. -std=c++11 -pthread 
LDFLAGS= -I. -lm -pthread -lpthread
SOURCES= task.cpp main.cpp Node.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=task

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o 
	rm -f $(EXECUTABLE)
