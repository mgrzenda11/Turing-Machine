# Turing-Machine
Turing Machine in C


A fully functioning Turing Machine written in C. It will ask the user for an input file with a .txt extension. Below is a sample input file

111B1111 
5
0
4
0 1 1 R 0 
0 B 1 R 1
1 1 1 R 1
1 B B L 2
2 1 B L 3
3 1 1 L 3
3 B B R 4

This file will add two unary numbers together (3 and 4). Any blank space is indicated by the "B" character. The first line is the start state (in this case 111B1111). The second line is the number of states (5 for this file). The third line is the start state (0) and the fourth line is the end state (4). The lines after this make up the state machine which has 5 parts: State, ReadVal, WriteVal, MoveDirection, NewState.
