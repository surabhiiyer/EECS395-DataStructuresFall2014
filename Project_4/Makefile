all: proj4

proj4: main.o dijkstra.o minHeap.o 
		  g++ -g -o proj4 main.o dijkstra.o minHeap.o

main.o: main.cpp
		g++ -c main.cpp

dijkstra.o: dijkstra.cpp 
			g++ -c dijkstra.cpp 

minHeap.o: 	minHeap.cpp 
			g++ -c minHeap.cpp 
clean:
		rm -rf *o proj4
