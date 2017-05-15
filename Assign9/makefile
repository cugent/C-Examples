# CSCI 241 -- Spring 2015 -- Polymorphism Example makefile
#
# Amy Byrnes

CC = g++
CCFLAGS = -Wall -O
ASSIGN = assign9
CLASS1 = Shape
CLASS2 = Rectangle
CLASS3 = Circle
CLASS4 = Triangle

	
$(ASSIGN) : $(ASSIGN).o $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o
	$(CC) $(CCFLAGS) -o $(ASSIGN) $(ASSIGN).o $(CLASS1).o $(CLASS2).o $(CLASS3).o $(CLASS4).o

$(CLASS4).o : $(CLASS4).cpp $(CLASS4).h $(CLASS1).h
	$(CC) -c $(CCFLAGS) $(CLASS4).cpp

$(CLASS3).o : $(CLASS3).cpp $(CLASS3).h $(CLASS1).h
	$(CC) -c $(CCFLAGS) $(CLASS3).cpp

$(CLASS2).o : $(CLASS2).cpp $(CLASS2).h $(CLASS1).h
	$(CC) -c $(CCFLAGS) $(CLASS2).cpp

$(CLASS1).o : $(CLASS1).cpp $(CLASS1).h
	$(CC) -c $(CCFLAGS) $(CLASS1).cpp

$(ASSIGN).o : $(ASSIGN).cpp $(CLASS1).h
	$(CC) -c $(CCFLAGS) $(ASSIGN).cpp

clean :
	- rm *.o
	- rm $(ASSIGN)
