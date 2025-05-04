# data-structures-assignment1
N-Queens problem solution in C++

*screen recording here: https://youtu.be/-bxb-5Ht_Ok*

To run the file, type `make` to compile the code to an executable called Nqueens, which you can then run the executable on command line with `./Nqueens`. Simply type in the number for the size of the grid you want, and the program will generate a valid solution for the N-Queens such as...
```
Please enter desired NxN grid size: 8

...

♠ □ ■ □ ■ □ ■ □ 
□ ■ □ ■ ♠ ■ □ ■ 
■ □ ■ □ ■ □ ■ ♠ 
□ ■ □ ■ □ ♠ □ ■ 
■ □ ♠ □ ■ □ ■ □ 
□ ■ □ ■ □ ■ ♠ ■ 
■ ♠ ■ □ ■ □ ■ □ 
□ ■ □ ♠ □ ■ □ ■ 

Valid solution found!
```
If you type in a number too large, the program will take to long to generate a solution. So it stops itself and asks for a smaller number...
```
Please enter desired NxN grid size: 15
Sorry, 15 is bigger than the max board size (14) for this program.
Please enter desired NxN grid size: |
```
If you want to compile and run the program at the same time, you can type `make run`
