all: wordladder

wordladder: main.o graph.o 
		g++ -g -o wordladder main.o graph.o

main.o: main.cpp
		g++ -c main.cpp

graph.o: graph.cpp
		g++ -c graph.cpp

clean:
		rm -rf *o wordladder
