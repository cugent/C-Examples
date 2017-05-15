#Assignment 4

CC = g++
CCFLAGS = -Wall

FILE = assign4
CLASS = Vector3

$(FILE): $(FILE).o $(CLASS).o
	$(CC) $(CCFLAGS) -o $(FILE) $(FILE).o $(CLASS).o

$(FILE).o: $(FILE).cpp $(CLASS).h
	$(CC) $(CCFLAGS) -c $(FILE).cpp

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CC) $(CCFLAGS) -c $(CLASS).cpp

clean:
	- rm *.o $(FILE)
