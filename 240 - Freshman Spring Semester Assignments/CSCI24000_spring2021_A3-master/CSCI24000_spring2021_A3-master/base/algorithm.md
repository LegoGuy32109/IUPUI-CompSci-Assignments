### Goals ###
I am going to have horses race each other across a track. After getting a seed to generate randomness, the 5 tracks will be displayed showing the horses at the start lined up, and subquestially have each horse move forward on a coin flip showing the progress each round. Horses will only move 1 space on a track 15 spaces long. When a horse finishes, all horses stop and the game is over with a lines saying which horse one, or which horses tied!

### Inputs ###
The user will input an integer for a random seed for the program. Must be an integer

### Outputs ###
The prompt for the seed
The steps as the horses move along the track until one wins
The winner(s) as Horse [num] wins! or Horse [num] and Horse [num] ... tie!

### Steps ###
I plan on using 4 functions to organise the computing for this program,
1. a void printLanes() to display the lanes and where the horses are
2. a void round() that will change the position of all horses at once, if the coin flip is in their favor, this will be run between printLanes()
3. a bool checkWinner() to return true if there is a winner, or whatever is most convenient, to stop a while loop I may have it return false
4. a void whosWinner() to print the winnser(s) to the screen, in the same notation I mentioned earlier

I will also have the int array lanes {0, 0, 0, 0, 0} as a global variable before my main.

In main, I will prompt user for seed and get it with cin, because it's just an int it's easy. Then I srand the seed to get the randomness going, and I'll have a while loop with the checkWinner as it's parameter telling it when to stop, and I'll be calling round() in that loop. After that the end of my main will display whosWinner().

In printLanes() a double four loop will print each . in the lane, then print the next lane. A conditional will print the num of the horse instead of the . If the lanes array position value equals where it is in the four loop. 

In round() I loop through the lanes array incrementing the position if rand()%2 is equal to 1, it has to be 1 or the example in assignment won't match for seed 700, and that's how they're testing my program with use cases. Round will call printLanes() at the end. NOTE: The first thing the user sees will be after the first round, so horses could be moved ahead one space.

In checkWinner() I simply loop through lanes array seeing if any position value is >= 15. If so I return the bool to stop loop.

In whosWinner() I have a string called winText that is empty, but I will add things to it then print it. I loop through lanes again and if the position is >= 15 like before I add to winText "Horse ", and I add the int i for index to an ostringstram called ss, ss << i, and add ss.str() to winText. after that I add an " and " and increment a wins integer by 1. After the loop I will then remove the last "and " added, notice I am leaving a space for after the number for this next word. I check if wins is >1, and if it is I add "tie" to winText, if not I add "wins". I then print winText to the screen adding an "!" for good measure.

### Sidenote ###
After working on this assignment, to get the output the way I wanted it in whosWinner, I had to include <string> and <sstream> to work around a bug where I couldn't cast i in the for loop to a string value to store in winText, so I had to use this ostringstream which I don't understand but it works. I also include <stdlib.h> for the srand and rand funcs.
