### Goals ###
For this program, It's going to look idetical to the one I did last week, I just need to compartmentalize it into two objects, Horse and Race, as well as a main.cpp file to run it. So the biggest issue I have is making sure the classes and their headers all connect to one another without issue, `#include horse.h` for race.h, and race.cpp, anytime code is referencing the horse or race class I have to make sure they're included. To start, I should make sure my makefile works correctly, because that's what is compiling all the files into an executable then running it. The graders for this assignment will just be typing in `make run` and expect the program to work, so get that right. 

I predict my file structure to look like this, 
| header files | c++ files | object files |
| ------------ | --------- | ------------ |
| horse.h      | horse.cpp | horse.o      |
| race.h       | race.cpp  | race.o       |
|              | main.cpp  | main.o       |

The makefile will create the object files, and then combine them into an executeable. I write the header and c++ files.

### Inputs ###
The user is typing in an integer for the seed to be randomized in the program.

### Outputs ###
The user is prompted for a seed
The program displays each step of the race as the horses start at the beginning, and some move forward while others don't. It displays all of the steps until one of the horses crosses the finish line, dissapearing from view symbolising their departure from the plane of normalacy and entering the realm of champions.
A statement will declare which horse is the winner, or which horses tied, or even the incredibly rare chance they all cross the finish line if the seed is say...  `36095, 82507, 111802, 158355, 170094, or 185511.` (I got these seeds from last week ok I'm just having some fun) 

### Steps ###
Write makefile to create the object files listed earlier off of those header and c++ names. 

Write the headers to follow the UML attribute and method structure Mr. Harris gave us in the assignment

Write the c++ files as the actual code for the methods described in the headers, inheiriting from the class Horse and Race defined in the respective headers.

Race::start() is the biggest function, because inside it is the while loop that prints each lane for each step of the game, and checks if there is a winner with it's internal logic, and says who one at the end of start.

main.cpp is fairly simple, it doesn't need a header and it only asks the user for a seed then creates a race object to call the start function. 

horse.h/horse.cpp are good files to start writing because they're pretty contained, and don't need to inherit from anything else, make sure you can .getPosition() of a Horse object and advance() the horse's position on a coinflib by using the rand() function (include rand library)

race.h/race.cpp includes the horse.h so it can create the attribute h[], an array of horse objects for the track each with their own position. I don't know why we need a Race(int horseNum) constructer cause I can just set the default to length = 15, but its on the UML so it's going in. 

the race class has a printLane(int horseNum) method, that makes it seem this will only print one lane out of the 5 for the whole track. My answer to this function last week was having it print all the tracks at once with a double for loop, but that parameter only accepts a single int, the horse's number, so it can't access all of h[]s positions with one index. I could go over it's head but I feel to be safe I'm just going to follow the UML as close as possible, printLane() will print only one lane.


