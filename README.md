# Turing-Machine
Turing Machine in C


A fully functioning Turing Machine written in C. It will ask the user for an input file with a .txt extension. A sample input file is included with the repository.

This file will add two unary numbers together (3 and 4). Any blank space is indicated by the "B" character. The first line is the initial tape input (in this case 111B1111). The second line is the number of states (5 for this file). The third line is the start state (0) and the fourth line is the end state (4). The lines after this make up the state machine which has 5 parts: State, ReadVal, WriteVal, MoveDirection, NewState. tab

The tape is implemented via a doubly linked list. 
