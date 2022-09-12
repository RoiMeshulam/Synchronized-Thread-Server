# Authors
Arik Tatievski

Roi Meshulam

# What is this project?

This project is a synchronized multi-threading server using a Stack to save data.

# The way we made our project:
The server runs an infinite loop and can listen to 10 users at the same time.

When the server gets a connection he runs a thread to handle the sapsific clients request.

Client can either "PUSH -text-*, *POP*, *PEEK*, any other command will be denided.

Push - push a string to the stack.

Pop - removes the head of the stack and returns it.

Peek - reads the head of the stack and returs it.

The server suppots synchronized through mutex.
The server allocates space in the stack using a private malloc.

# How to use our project:

Write in a bash environment "make all".

Please run ./Server to activate our server

Please run ./Client to activate a client (Not an infinite connection does dummy commands and disconnects).

You can also run your own client as long as it matches the IP/PORT written in "Server.c"

# Extras
You can also write in a bash environment "make test" and run the ./Test file to get a confirmation that the lock is successfull.

Test logic:

If 100 different threads will push data and increase a global variable he will reach a sum of X.

If 100 different threads will try to pop data and remove it from x, we have 2 possible reasults:

If the reasult is 0 each thread poped data in his turn and no threads reached the same data.

If the reasult is NOT 0, one or more threads werent locked during the pop() and got from the stack same information.

# Hope you find good usuage of this project!
