# Puzzle

##CHallenge 1
Create a command line program that reads from a file and solves the following problem through simulation: 
You have a certain number lightbulbs each with a different colour. The number of light bulbs is determined by an input file. The program should randomly pick the number of the lightbulbs specified by the last line in the file and determine the number of unique colours drawn. Extend the simulation to determine the expected number of unique colours in this scenario (in other words, the average output of the simulation).
Requirements:
 - Code should be written in C or C++
 - Completion within 24 hours
 - Include source code and makefile/compilation command for either windows, macOS or linux using g++
 - You must read and parse the “lb-challenge.inputs” file. File must be provided as a command line argument
 - You must output the expected value of the scenario before quitting
 - Code should be commented or written in a self-commenting fashion
 
Input file general form (describes the meaning of the inputs in the attached lb-challenge.inputs file):
 
[colour1] [number bulbs]

[colour2] [number bulbs]

… (as many lines as colours)

[bulbs to select]
