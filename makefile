all: debug

debug:
	mkdir -p bin
	clang++ -std=c++14 inter.cpp main.cpp -o bin/flashcard -O0 -Wall
	./bin/flashcard

release:
	mkdir -p bin
	clang++ -std=c++14 inter.cpp main.cpp -o bin/flashcard -O3 -Wall
	./bin/flashcard

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
