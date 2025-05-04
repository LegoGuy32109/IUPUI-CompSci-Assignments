# data-structures-assignment2
Creating a Binary Search Tree (BST) and finding the kth smallest element in C++

*screen recording here: https://youtu.be/QLyp2Tg61zg*

To run the file, type `make` to compile the code to an executable called BST, which you can then run the executable on command line with `./BST`. The program will generate a Binary Tree fron the given numbers in the assignment: 
`[6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99]` and display it to the user.
```
                  6
            17
                  20
      41
                  45
            52
                  57
65
                  71
            76
                  79
      87
                  92
            95
                  99
```
It will then ask `please enter the kth element you'd like to search: ` prompting the user to enter an integer between 1-15, the possible indexes of the elements in the tree. It then finds the kth smallest element from that index using an inOrder traversal of tree storing it in a queue, then finding the right element value and outputting it to the user.
```
Tree has been constructed, please enter the kth element you'd like to search: 3
The 3rd smallest element is 20
```
If you type in a number that doesn't work with the given data, it will prompt you to try again. 
```
Tree has been constructed, please enter the kth element you'd like to search: -4
Sorry element -4 isn't valid with this tree of 15 elements
Tree has been constructed, please enter the kth element you'd like to search: |
```
If you want to compile and run the program at the same time, you can type `make run`
