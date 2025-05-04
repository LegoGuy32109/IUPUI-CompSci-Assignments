# data-structures-assignment5
Hash table to store many strings loaded from file

*screen recording here: https://youtu.be/AAm4gUsyd34*

To run the file, type `make` to compile the code to an executable called 'Hash', which you can then run the executable on command line with `./Hash`. The program will generete a Hash table from the given strings in `Dictionary.txt`: 
```look for a word: snetence
do you mean sentence?
yes
True
see
set
23 micro-sec
```
if the program can't find the word in the dictionary it will compared to other words with the same letter, and try to calculate the most likely word. Words of similar length are weighted more heavily than those that aren't. When you type 'yes' the program will print words it has that contains the same first two letters. This is the same output for a word that is in the hashtable. If you respond no or there are no words with the same first letter...
```
look for a word: xylaphone
False
3 micro-sec
```
the program says 'False'. Every run displays the time it took to run the program.

If you want to compile and run the program at the same time, you can type `make run`
