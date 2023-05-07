main : ensemble.o main.o
	g++ ensemble.o main.o -o main
ensemble.o : ensemble.cpp ensemble.h
	g++ ensemble.cpp -c
main.o : main.cpp ensemble.h
	g++ main.cpp -c
