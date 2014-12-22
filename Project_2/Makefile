all: Project2 

Project2: main.o qst.o bst.o
		g++ -g -o Project2 main.o bst.o qst.o

main.o: main.cpp
		g++ -c main.cpp

qst.o: qst.cpp
		g++ -c qst.cpp

bst.o: bst.cpp
		g++ -c bst.cpp

clean:
		rm -rf *o Project2

