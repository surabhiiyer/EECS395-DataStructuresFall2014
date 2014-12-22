all: SpellChecker 

SpellChecker: main.o Dictionary.o HashTable.o SpellCheck.o
		g++ -g -o spellcheck main.o Dictionary.o HashTable.o SpellCheck.o

main.o: main.cpp
		g++ -c main.cpp

Dictionary.o: Dictionary.cpp
		g++ -c Dictionary.cpp

HashTable.o: HashTable.cpp
		g++ -c HashTable.cpp

SpellCheck.o: SpellCheck.cpp
		g++ -c SpellCheck.cpp

clean:
		rm -rf *o SpellChecker
