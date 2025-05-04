#this blackbelt assignment was written by Josh Hale for knock knock assignment, and features steers attracted to facts and logic
import time
#important for picking a random question
import random
def wait(sec):
time.sleep(sec)
#better documentation in joshHaleKnockKnock.py
#this program is the same as the nonblackbelt except for the end, go to line 54 for new differences
print("Howdy!")
wait(1)
name = input("What's your name partner?\n: ")
print("Welcome to the ranch, "+name+".")
wait(1)
print("would you like to hear a knock knock joke?")
wait(2)
print("I'm sure you would "+name+"!")
wait(1)
print("knock knock... (say 'who's there?')")
who = ""
while (who != "who's there?"):
    who = input(": ")
    if(who == "who's there?"):
        continue
    print("Sorry I'm waitng for a 'who's there?', not "+who)
print("Tank!")
print("(Now say 'tank who?')")
while (who != "tank who?"):
    who = input(": ")
    if(who == "tank who?"):
        continue
    print("Sorry I'm waitng for a 'tank who?', not "+who)
print("Bless you!")
wait(2)
print("Haha, it sounded like you sneezed.")
wait(2)
print("anyway...")
wait(1)
print("I'll be frank with ya "+name+", are you any good at cattle rustling? \nI have some steers that escaped and could really use some extra hands.")
wait(4)
print("I'm going to assume you said yes, why else would you be here?")
wait(2)
print("My steers are a little unusual, they're attracted to facts and logic.")
wait(3)
print("They'll ask you random triva questions that are very easily google searched")
wait(2)
print("get them right, and they'll gladly follow you back into their pen")
wait(2)
print("Now I'm sure you have questions, like why can't I, A rancher, do this myself?")
wait(2)
print("Well I'm simple folk "+name+", \nand my smartphone doesn't get good reception down here in the sticks, \nso I can't google nuttin!")
wait(4)
print("Oh here comes one now! Good luck!")
wait(2)
#Python dictionary with the questions as the key, and the values as the answer
questions = {
    "What's the earth's current distance from the sun? Tell me your answer in millions of miles.": "93.017",
    "How many people are on facebook? Tell it to me as a decimal in billions.": "2.7",
    "Which insect has the longest lifespan? Say it as a phrase.": "queen of termites",
    "How many people play Fortnite? Say it in millions.": "250",
    "How old is Mario jumpman Mario? Give me the number of years.": "39",
    "What's the name of the newest fighter for Super Smash Brothers? Tell me in lowercase": "steve",
    "What's the title of the best selling video game of all time? Remember to say it to me in lowercase.": "minecraft",
    "What's the most popular dog name for a male dog? Remember, lowercase please.": "charlie",
    "What's the most popular cat name of 2020? Of course say it in lowercase.": "oliver"
}
#wrongAns variable tracks incorrect guesses
wrongAns = 0
#loops through every question
while (len(questions) > 0):
    print("A steer approaches...")
    wait(0.5)
#picks a question randomly
    curQ = random.choice(list(questions))
#sets answer to empty JIC two questions have same answer
    ans = ""
#loops through inputs from user, stopping when correct
    while(ans != questions[curQ]):
#asks question and stores answer in 'ans'
        ans = input(curQ+"\n: ")
#if answer is right and matches the dictonary answer it breaks out of this while loop
        if(ans == questions[curQ]):
            print("Moo! That's right, I'll get back in the pen.")
            wait(0.5)
#continue skips the rest of the code in this nested while loop
            continue
#next 3 lines would be skipped if continue was hit
        print("Moo.. That's not right "+name+", let me ask you again...")
#increments wrong answer by 1
        wrongAns+=1
        wait(1)
#deleting the question happens outside of the nested loop since error is thrown otherwise
    del questions[curQ]
#every question has been answered correctly and there are no more questions in the dictonary, now just trivial diologue stuff
print("\nBoy howdy! You done got every steer back where it needs to be!")
wait(2)
print("That sure was a lot of steers, at least 7 of em.")
wait(1)
#cast integer to string for safety's sake
print("And you only had "+str(wrongAns)+" wrong guesses, very impressive.")
wait(2)
print("Thanks so much for coming "+name+"!\nYou're a real life saver.")
wait(5)
print("--PROGRAM TERMINATED--")
