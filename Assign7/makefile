#Assignment 4

CC = g++
CCFLAGS = -Wall

FILE = assign7
CLASS = Stack

$(FILE): $(FILE).o $(CLASS).h
	$(CC) $(CCFLAGS) -o $(FILE) $(FILE).o

$(FILE).o: $(FILE).cpp $(CLASS).h
	$(CC) $(CCFLAGS) -c $(FILE).cpp


clean:
	- rm *.o $(FILE)
