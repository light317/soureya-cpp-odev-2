all: build run


build:
	g++ -I ./include/ -o ./lib/Cell.o -c ./src/Cell.cpp
	g++ -I ./include/ -o ./lib/Tissue.o -c ./src/Tissue.cpp
	g++ -I ./include/ -o ./lib/DataReader.o -c ./src/DataReader.cpp
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/Organism.o -c ./src/Organism.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/System.o -c ./src/System.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp

	g++ -I ./include/ -o ./bin/main ./lib/Cell.o ./lib/Tissue.o ./lib/DataReader.o ./lib/Organism.o ./lib/Organ.o ./lib/System.o ./lib/Exception.o ./lib/Radix.o ./lib/BST.o ./src/main.cpp

run:
	./bin/main