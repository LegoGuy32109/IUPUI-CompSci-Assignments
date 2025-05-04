#This program is written for the HighLow assignment
#Gotta import the random module to get a random guess
import random
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
