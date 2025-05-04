###GOALS###
I like the program I have so far, but I want it to be more professional. I was limited in my base to only have a few pets for hard coding if statements. For this blackbelt I'd like to start by making the amount of pets variable, and understand when the user types in an integer and check automatically if that's a valid pet number. I'll need to parse the int in a try catch so it doesn't catch the program and ruin the data. That was an issue in my base. I also am going to overhaul the input so that when the user is asked if they want a 'chameleon' or a 'mole-rat' they don't have to type in the whole thing cause that was very annoying. I had the while loop catch it but still that takes a long time, just the first letter is fine cause they're different. I think I'll also do that for the yes and no questions. Oh! and add delete!

###INPUTS###
Now the user just needs to type in the first letter of their option and it will understand where to go. Even uppercase will work by using the .toUpperCase() method for strings in java. They can now type in the number for accesing the pet like before, but it can go on forever and not be limited to 4 pets like the base.

###OUTPUT###
Not much will change output wise, but the list of the animals can go theoretically forever now. Expands dynamically
 
###STEPS###
For the first letter answer, substring the user input for the first character then upper case it and see if it .equals() what I want like "Y" or "N"

For the dynamic amount of pets, in new pet just have the user choose which species and add it to the pets array list like before, but I don't need the size limit for the menu because:
In a try block parse the user's answer for the animal they pick, if it is an integer check if it's less than or equal to the size of the pets and it's bigger than 0, 0 won't work. If the catch happens or the integer isn't in range, say that isn't a valid number. I can also do this for the deleting section of the menu, nice!
