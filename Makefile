all : hello
hello : main.o solution.o simulate.o 
		g++ main.o solution.o simulate.o -o tsp
main.o : main.cpp tsp.h
		g++ -c main.cpp tsp.h
solution.o : solution.cpp
		g++ -c solution.cpp
simulate.o : simulate.cpp
		g++ -c simulate.cpp

clean:
	rm -rf run
	rm -rf main.o
	rm -rf bst.o
	rm -rf rbt.o
