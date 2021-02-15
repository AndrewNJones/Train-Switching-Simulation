# CS315 Makefile for Program 1: Trains
# Feel free to modify as needed.
# Original author: Raphael Finkel 1/2021
# Modifications made by: Andrew Jones

CFLAGS = -Wall -g
CPPFLAGS = -Wall -g

NUMTRAINS = 5
NUMCARS = 6
NUMSTEPS = 1000

SEED = 49

# compile and run the program, placing the result in output.txt
run: trains randGen.pl
	./randGen.pl $(SEED) | ./trains $(NUMTRAINS) $(NUMCARS) $(NUMSTEPS) > output.txt
	less output.txt

# get the randGen.pl program
randGen.pl:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/utils/randGen.pl
	chmod +x randGen.pl

.PHONY: clean
clean:
	rm -f randGen.pl trains workingTrains tmp* toSubmit.zip
