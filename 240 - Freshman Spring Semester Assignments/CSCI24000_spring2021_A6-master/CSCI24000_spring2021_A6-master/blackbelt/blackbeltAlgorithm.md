### GOALS ###
I would like to expand the functionality of the date object, and when I getDate() I would like to display the month name rather than the number
I want to create a classroom object that holds an array of students, and from that classroom you can get the shortList and fullReport. The classroom object can read from a specific file name you can pass it to populate it. The classroom object can also create the reports with a file name you give it like "classReport" or "longReport" and create a text file with that name. 

### INPUTS ####
A students.dat file, or whatever the data is on as long as it's a .dat

### OUTPUTS ###
Whatever the program is given as output file names, most likely shortReport.txt and fullReport.txt

### STEPS ###
Create Classroom class, and add necessary methods mentioned above. To store an instance in the stack make sure there is a delete method too, that simply deletes the array. 
Change main.cpp to reflect the changes, create a classroom object rather than an array of student objects. 
classroom should have a method to update a student given an index and a string of info, that it then creates a student object with at that index in the internal array
have if else if chain in date.cpp/getDate() to return month name rather then number
