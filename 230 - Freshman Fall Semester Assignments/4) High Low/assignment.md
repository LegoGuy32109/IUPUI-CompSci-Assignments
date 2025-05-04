# High Low
Due: Fri Oct 16, 2020 11:00pmDue: Fri Oct 16, 2020 11:00pm
96/100
96/100 Points
Attempt
Attempt 1

Review Feedback
SUBMITTED: Oct 16, 2020 10:52pmSUBMITTED: Oct 16, 2020 10:52pm
Attempt 1 Score:
96/100

Anonymous Grading:
no
Unlimited Attempts Allowed
Available until Dec 11, 2020 11:00pmAvailable until Dec 11, 2020 11:00pm
High Low Lab
Preparation
Online students please watch videos up to variables, loops, and conditions

Objectives
Create a program that illustrates your understanding of conditions. Create a "High-Low" game which allows the user to play a game with the computer. The game will require input, output, branching and loop behaviors.

Discussion
The game begins with the computer generating a random integer between 1 and 100. The user will guess a number, and the computer will indicate whether the guess is too high, too low, or correct. This will continue until the user has correctly guessed the computer's number.

```
I'm thinking of a number between
1 and 100. Guess a number, and I'll tell you
if you're too high, too low, or got it right.
Good luck!
1) Please enter a number
50
Too low!
2) Please enter a number
75
Too low!
3) Please enter a number
88
Too high!
4) Please enter a number
80
Too low!
5) Please enter a number
84
Too high!
6) Please enter a number
82
Too low!
7) Please enter a number
83
Correct!
It took 7 turns.
```

Hints
You'll need some type of loop around the main program
Generate a random number (look into the Random module)
Get input from the user
You'll need several comparisons of user's guess to target value
Don't forget to give feedback to the user
Watch for endless loops!
Don't forget to use debug mode if you get stuck
Submission
Please submit the following on Canvas:

Your .py file (NOT a link to your pythonanywhere page)
A .txt file describing your algorithm (congruent with the requirements for algorithm files described in the announcement about algorithm files)
If you are turning in a blackbelt version, submit your blackbelt code as a separate .py file and your blackbelt algorithm in a .txt file.
Blackbelt Challenge
Once you get the basic form working, see if you can write a program that goes the other direction. The user generates the number, and the computer tries to guess it. A sample run might look like this:

Please think of a number between
one and one hundred. I'll guess
your number. You tell me if I'm 
too high, too low, or correct.
I guess: 50
too (h)igh, too (l)ow, or (c)orrect?
h

I guess: 25
too (h)igh, too (l)ow, or (c)orrect?
l
I guess: 37
too (h)igh, too (l)ow, or (c)orrect?
l
I guess: 43
too (h)igh, too (l)ow, or (c)orrect?
h
I guess: 40
too (h)igh, too (l)ow, or (c)orrect?
high
Sorry, I didn't understand you...
I guess: 40
too (h)igh, too (l)ow, or (c)orrect?
h
I guess: 39
too (h)igh, too (l)ow, or (c)orrect?
h

I guess: 38
too (h)igh, too (l)ow, or (c)orrect?
c
I got it! it took 7 turns.
Feel free to add on other blackbelt assignments, but start with this one if you are writing any blackbelt versions.
