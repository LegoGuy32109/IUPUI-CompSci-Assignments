### GOALS ###
I am given an input.txt file that will be worded like this:
```
1,4,2
ham
4,2,0
plant
```
for an unspecified amount of words, but all integers will be listed above with commas inbetween. I want to have each word printed as many times as the 3 integers above put together. For ham in the example, that would be 7 times like this:
 ``` ham,ham,ham,ham,ham,ham,ham```
 with commas inbetween. This is done for every word in the input.txt with the integers above them.
 
 ### STEPS ###
 Set up the variables for the input text stream and the input and output files as well as 3 integers, a string var, and a char var.
 
 open up input.txt in a while loop getting each line
 
 put the text from getline in the input text stream 
 
 convert the text stream into three integers, with a char variable between the intgers like this 
 `textstream >> int1 >> someChar >> int2 >> someChar >> int3 `
 
 use another getline to get the next line of input.txt which will be the word to repeat
 
 use the ints as a conditional in a for loop where you add the word and a comma to a string var
 
 substring the string to get rid of the last comma ,
 
 append that string to the ouput.txt you created at the end of the while loop
 
 after the while loop is over end the program after closing
 
