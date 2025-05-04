### GOALS ###
I am trying to store student data on the heap. I read data from a student.dat file and store it into student objects. I then take that data and organise it onto two new files, longReport.txt and shortReport.txt.
The long report includes all the data with short report only the names. Having stored all the variables in the heap, I can then delete the student objects stored in an array to free up resources when the program is over. My goal is to not leak any memory.

### INPUTS ###
A students.dat file with the students on each line and the data seperated by commas

### OUTPUTS ###
A longReport.txt with all the data of the students
A shortReport.txt with all the names of the students, I will list them with a number
1) Jessica Robins

### STEPS ###
This is the class structure I'm working with, see UML for more details
| header files | c++ files | object files |
| ------------ | --------- | ------------ |
| date.h      | date.cpp | date.o      |
| address.h       | address.cpp  | address.o       |
|   student.h     | student.cpp  | student.o       |
|              | main.cpp |        main.o |
student inclues address and date, and main includes all 3

in main create an array of student objects

open the .dat and parse line by line

create a student object passing the line to the constructor and adding it to the array

in the student object constructer, parse the data between commas, creating Dates and Address in the heap by feeding it that specific string

The dates and addresses contructers take the string and create their attributes from it, they also have getters to get their data in the next step...

The student object has 2 methods to return the students name for short report, and everything for the long report.

Open a new file "longReport.txt"

loop through the array calling the long report method for each student and passing it to the file

close longReport.txt

open a new file"shortReport.txt"

loop through exactly like before calling getting student name and passing it to the file

close shortReport.txt

delete the array, which will delete all the sub attributes as well
