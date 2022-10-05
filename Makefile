runlist: main.o Stack.o
	g++ -o runlist main.o Stack.o

main.o: main.cpp 
	g++ -c main.cpp

Stack.o: Stack.h Stack.cpp
	g++ -c Stack.cpp

clean: 
	rm runlist main.o Stack.o