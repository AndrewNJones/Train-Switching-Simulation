# Train_Station
*This is a class project*

Author: Andrew Jones
CS 315 - Project 1
February 12, 2021

Description:
This program simulates a train switching station. It uses doubly-linked-lists
and random number generation to simulate a scenario where trains will switch
cars with each other. Each 'turn', a train is randomly selected to donate a car
to another randomly selected train. The program takes 3 arguments that determine 
the number of trains, the number of cars for each train (initially), and the 
maximum number of turns before the program terminates. The program will terminate 
before it reaches this number if one of the trains reaches 0 cars. Included within 
this repository are the program, a MAKEFILE for the program, and this text document.

How to run the program:
This program is easily can be easily ran in Linux using the given Makefile.
The Makefile is designed so that the user can simply type "make" into the
command line and the program will compile and run with a predetermined seed for
random number generation and program arguments. After the program is ran once 
using this method, if you wish to run the program again with your own parameters, 
type in the command line:

./randGen.pl a | ./trains b c d 

where:
a = seed for the random number generator
b = number of trains
c = number of cars per train
d = maximum number of turns
