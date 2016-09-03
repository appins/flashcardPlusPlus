all: debug

debug:
	mkdir -p bin
	clang++ -std=c++14 inter.cpp main.cpp -o bin/learn2 -O0 -Wall
	./bin/learn2

release:
	mkdir -p bin
	clang++ -std=c++14 inter.cpp main.cpp -o bin/learn2 -O3 -Wall
	./bin/learn2
