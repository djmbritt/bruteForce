CC = g++

CompileParms = -c -Wall -Wextra -std=c++1y -g

OBJS = stand.o main.o

Opdr: $(OBJS)
	$(CC) $(OBJS) -o Spel

stand.o: stand.cc stand.h
	$(CC) $(CompileParms)  stand.cc

main.o: main.cc stand.h
	$(CC) $(CompileParms)  main.cc

