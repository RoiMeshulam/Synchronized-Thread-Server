CC=gcc
AR=ar
FLAGS= -Wall -g

all: client server
test: test2

client:  Client.o
	$(CC) $(FLAGS) -o Client Client.o

server:  Server.o
	$(CC) $(FLAGS) -pthread -o Server Server.o

Server.o: Server.c
	$(CC) $(FLAGS) -pthread -c Server.c

Client.o: Client.c
	$(CC) $(FLAGS) -c Client.c

test2:  Test.o
	$(CC) $(FLAGS) -pthread -o Test Test.o

Test.o: Test.c
	$(CC) $(FLAGS) -pthread -c Test.c

.PHONY: clean all
clean:
	rm -f *.o Client Server Test