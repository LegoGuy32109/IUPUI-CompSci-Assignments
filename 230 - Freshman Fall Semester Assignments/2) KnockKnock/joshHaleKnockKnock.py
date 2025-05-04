#This program was written by Josh Hale for Knock Knock assignment
#import time library to add waiting in program, I like the effect
import time
#def defines a function I call wait, where I take a parameter 'sec' storing a double that I use in the sleep function from the time library that will halt the program for that many seconds. I just don't feel like typing time.sleep() all the time.
def wait(sec):
    time.sleep(sec)
#print a message to the screen
print("Howdy!")
#program waits one second
wait(1)
#assigns the variable 'name' the value inputted from the prompt
name = input("What's your name partner?\n: ")
#the print statement includes the variable name, which is displayed alongside the text inbetween the comma and period
print("Welcome to the ranch, "+name+".")
#another wait for one sec
wait(1)
#normal print statement
print("would you like to hear a knock knock joke?")
wait(2)
#More of the same, I explained it earlier
print("I'm sure you would "+name+"!")
wait(1)
#This print included '' and () that are displayed because the string is wrapped in "", the parenthesees are to hint to the user what to input to get the program moving forward
print("knock knock... (say 'who's there?')")
#variable 'who' is created to check their input and make sure it's correct for the context, intialized as an empty string
who = ""
#this while loop will repeat until the user types in the correct response, in this case "who's there?"
while (who != "who's there?"):
#first line of loop records input storing in who
    who = input(": ")
#if statement checks if it's right
    if(who == "who's there?"):
#if right, continue breaks out of thw while loop so it doesn't print the last statement in the loop
        continue
#print they were wrong, but I tell em what they need to type as well as show what they did type so they can see where they went wrong
    print("Sorry I'm waitng for a 'who's there?', not "+who)
#if the while loop ever gets broken, you're here! so the next line of dialogue starts
print("Tank!")
#indicate next thing to say
print("(Now say 'tank who?')")
#this while loop is identical to the former, just checking for "tank who?" now
while (who != "tank who?"):
    who = input(": ")
    if(who == "tank who?"):
        continue
    print("Sorry I'm waitng for a 'tank who?', not "+who)
#now the program is done getting user input, so just some funny dialogue
print("Bless you!")
wait(2)
print("Haha, it sounded like you sneezed.")
wait(2)
print("anyway...")
wait(1)
print("thanks for running my program! It aint much, but it's honest work :)")
