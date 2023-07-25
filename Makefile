all: compile link

compile:
	g++ -I src/include -c main.cpp GameDriver.cpp player.cpp Enemy.cpp Block.cpp
link:
	g++ main.o GameDriver.o player.o Enemy.o Block.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio -l sfml-network