all: unix

unix:
	mkdir -p bin
	g++ -std=c++11 inter.cpp main.cpp -o bin/flashcard
	./bin/flashcard

win:
	mkdir -p bin
	g++ -std=c++11 inter.cpp main.cpp -o bin/flashcard.exe
	./bin/flashcard.exe

build:
	mkdir -p bin
	g++ -std=c++11 inter.cpp main.cpp -o bin/flashcard

build_win:
	mkdir -p bin
	g++ -std=c++11 inter.cpp main.cpp -o bin/flashcard.exe
