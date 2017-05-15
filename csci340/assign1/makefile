#
# PROGRAM:    assign2
# PROGRAMMER: Caleb Ugent
# LOGON ID:   z1729481
# DATE DUE:   2/12/15
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rules to compile source code files to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp
clean:
	-rm *.o assign1
