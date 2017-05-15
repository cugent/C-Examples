#Assignment 8

CC = g++
CCFLAGS = -Wall

FILE = assign8
CLASS = sorts
CLASS2 = quicksort
CLASS3 = mergesort
$(FILE): $(FILE).o $(CLASS).h $(CLASS2).h $(CLASS3).h
	$(CC) $(CCFLAGS) -o $(FILE) $(FILE).o

$(FILE).o: $(FILE).cpp $(CLASS).h $(CLASS2).h $(CLASS3).h
	$(CC) $(CCFLAGS) -c $(FILE).cpp


clean:
	- rm *.o $(FILE)
