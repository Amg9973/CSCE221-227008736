target: t1 t2
	@echo "Bulding Target"
	g++ main linkedlist -o lab10
t1: main.cpp linkedlist.cpp function.h
	g++ -c main.cpp -o main

t2: linkedlist.cpp function.h
	g++ -c linkedlist.cpp -o linkedlist

all: target
