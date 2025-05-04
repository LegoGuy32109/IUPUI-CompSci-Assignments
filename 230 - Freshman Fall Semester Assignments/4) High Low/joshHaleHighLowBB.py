#This Black Belt assignment was written by Josh for HighLow
#If you want to know how the A line code works check the other file
import random
#Find how many guess it would take in a range of x
def howManyGuesses(x):
    maxGuesses = 0
    while x>0:
        x/=2
        x = int(x)
        maxGuesses += 1
#Return the amount of times you can divide the range by 2 until it's 0
    return maxGuesses
#To tell if the computer guessed correctly
compRight = False
#If True path A. else B
userChoice = True
#Find out which path the user wants continuing to ask until it gets an a or b
while True:
    userIn = input("Let's play a game! Would you like to \n(A): Guess a number I'm thinking of 1-100 or...\n(B): Have me guess your number?\n(Type 'A' or 'B' to choose)\n :")
    if userIn == "A" or userIn == "a":
        print("Alright let's do that!")
        userChoice = True
        break
    elif userIn == "B" or userIn == "b":
        print("Ok, you're gonna love this...")
        userChoice = False
        break
    else:
        print("I didn't understand that, let me repeat myself...\n")
#A line, have user guess
if userChoice:
#Come up with a random number for user to guess
    randNum = random.randint(1,100)
#Clarify variable tracking how many wrong guesses
    wrongGuesses = 0
#Take the users input, assume they type an integer
    guess = input("Welcome to the HighLow Game! Guess a number that I've thought of between \n1-100 and I'll tell ya if you need to guess higher or lower...\n: ")
#Turn the input into an integer
    guess = int(guess)
#Check the 1% chance it's correct, if it's not loop until the user types in the right answer
    while guess != randNum:
#need to change input into an int again at the beginning of the loop
        guess = int(guess)

#Check if the guess is greater or less than the randNum, tell user accordingly and take their input again
        if guess < randNum:
            guess = input("Guess higher!\n: ")
        elif guess > randNum:
            guess = input("Guess lower!\n: ")
#If the guess is right, and it gets to here, break the while loop and don't count an incorrect guess.
        else:
            break
#Increment wrong guess if you've reached the end of the while and it was wrong
        wrongGuesses += 1
#Tell the user what it was, and how many wrong answers it took
    print("You guessed it! It was {}! It only took you {} wrong guesses :)".format(randNum,wrongGuesses))
    print("\nThank you for running my program, I hope you enjoyed :)")
#B line, computer guesses
else:
    minVal = 0
    maxVal = 0
    print("To start, I need the range of the numbers I am guessing. ")
#Get the min and max of the range from user
    while True:
        minVal = input("What's the minimum value? (as an integer)\n: ")
        try:
            minVal = int(minVal)
            break
        except ValueError:
            print("I didn't get that, could you type it again?")
            print("{} is the lower value, now...".format(minVal))
    while True:
        maxVal = input("What's the maximum value? (as an integer)\n: ")
        try:
            maxVal = int(maxVal)
            break
        except ValueError:
            print("I didn't get that, could you type it again?")
#Set the max guesses to the range or difference of the 2
    maxG = howManyGuesses(maxVal-minVal)
    print("Got it! The range is {} - {}, I bet I can find it in {} guesses.".format(minVal,maxVal,maxG))
#Keep track of how many guesses
    compIndex = 0
#Run for as many guesses as calculated, stopping if it reaches to that point
    for i in range(maxG):
#If the computer is right, break
        if compRight:
            break
#Set guess to the middle of current range
        compGuess = int(minVal + (maxVal-minVal)/2)
#Increment guess
        compIndex += 1
#Activate feedback loop until user gives answer
        feedbackR = True
        while feedbackR:
            feedback = input("Is your number {}?\nDo I need to guess (h)igher, (l)ower, or am I (c)orrect?\n: ".format(compGuess))
#Computer needs to go higher, set the minVal to the curent guess + 1 and calculate again in for loop
            if feedback == "h":
                minVal = compGuess + 1
                feedbackR = False
#Computer needs to go lower, set the maxVal to the curent guess - 1 and calculate again in for loop
            elif feedback == "l":
                maxVal = compGuess - 1
                feedbackR = False
#Computer got it right, break while and for loop telling computer is right
            elif feedback == "c":
                compRight = True
                break
            else:
                print("I'm sorry I didn't understand that...\n")
#for loop over without correct guess, user must have messed up
    if not compRight:
        print("That doesn't make sense, I should have found the number by now.\nI think you messed something up when you were answering. Try again?")
#Program worked and user did everything right and stats are displayed at end
    else:
        print("Awesome! The number was {}! And I got it in {} guesses!".format(compGuess,compIndex))
if compRight:
    print("Thank you for running my program, I hope you enjoyed :)")
