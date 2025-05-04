""" cardGame.py BlackBelt
Written by Josh Hale, it does 3 things and they are cool
"""
import random
import time

NUMCARDS = 52
DECK = 0
PLAYER = 1
COMP = 2

cardLoc = [0] * NUMCARDS
suitName = ("hearts", "diamonds", "spades", "clubs")
rankName = ("Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
"Ten", "Jack", "Queen", "King")
playerName = ("deck", "player", "computer")
gameList = ["War","Magic Trick","Quit"]
def whichGame():
    while True:
        print("Hey! What game do you want to play?")
        for i in range(len(gameList)):
            print("{}: {}".format(i+1,gameList[i]) )
        userIn = input("Type number or game here \n: ")
        try:
            if int(userIn) == 1 or int(userIn) == 2 or int(userIn) == 3:
                return int(userIn)
        except ValueError:
            if userIn.upper() == "WAR":
                return 1
            elif userIn.upper() == "MAGIC TRICK":
                return 2
            elif userIn.upper() == "QUIT":
                return 3

        print("I didn't understand {}, try again?".format(userIn))

def main():
    choice = 0
    choice = whichGame()
    clearDeck()
    if choice == 1:
        print("Let's play War!!\nDealing cards...")
        for i in range(int(NUMCARDS/2)):
            assignCard(PLAYER)
            assignCard(COMP)
        onTable = []
        print(cardLoc)
        while True:

            playerCard = drawCard(PLAYER)
            compCard = drawCard(COMP)
            print("\nYou play {}\nComputer plays {}\n".format(getCardName(playerCard),getCardName(compCard)) )
            onTable.append(playerCard)
            onTable.append(compCard)
            if(playerCard%13>compCard%13):
                print("You win the hand, adding cards to your deck...")
                for cardIndex in onTable:
                    cardLoc[cardIndex] = PLAYER
                onTable.clear()
            elif(playerCard%13<compCard%13):
                print("Computer wins the hand, adding cards to their deck...")
                for cardIndex in onTable:
                    cardLoc[cardIndex] = COMP
                onTable.clear()
            else:
                print("Cards match! Draw again...")

            try:
                win = cardLoc.index(PLAYER)
            except ValueError:
                print("Computer won, better luck next time.")
                break
            try:
                win = cardLoc.index(COMP)
            except ValueError:
                print("You won! Congrats!!")
            break

        main()

    if choice == 2:
        print("Ok, pick a card any card...")
        onTable = []
        for i in range(7):
            onTable.append(assignCard(COMP))
            print("{}: {}".format(i+1,getCardName(onTable[i])))
        print("\n")
        answer = ""
        while True:
            answer = input(": ")
            try:
                if int(answer) > 0 and int(answer) < 8:
                    break
            except ValueError:
                print("I didn't understand that, a number between 1 and 7 please...")
            continue
            print("I didn't understand that, a number between 1 and 7 please...")
        print("Ok let me think...")
        rangeNum = random.randrange(3,8)
        for i in range(rangeNum):
            time.sleep(1)
            print("...")
        input("Is your card the {}?\n: ".format( getCardName(onTable[int(answer)-1]) ) )
        print("I knew I would get it! Thanks for playing!!")
        main()

    if choice == 3:
        print("Shutting down.... so long....")

def getCardName(cardNum):
    thisSuitName = "unknown suit"
    #This algorithim explained in showCards()
    suitNum = NUMCARDS/len(suitName)
    for j in range(len(suitName)):
        if cardNum < (j+1)*suitNum:
            thisSuitName = suitName[j]
            break
    #Format same in showCards() minus player name
    return "{} of {}".format(rankName[cardNum%13], thisSuitName)

def drawCard(player):
    while True:
        card = random.randrange(NUMCARDS)
        if(cardLoc[card]==player):
            return card

#Set all NUMCARDS values in the empty array to 0
def clearDeck():
    for i in range(NUMCARDS):
        cardLoc[i] = 0

#Take which player to add card to as parameter 1,2
def assignCard(playerNum):
    #Loop through random choices until card in deck is found
    while True:
        #Set index to random number 0..51
        cardIndex = random.randrange(NUMCARDS)
        #find the card's location in cardLoc
        card = cardLoc[cardIndex]
        #Check if card is in deck, if it is set it to playerNum and break loop
        if(card == 0):
            cardLoc[cardIndex] = playerNum
            return cardIndex
            break
        #If the if statement didn't work, program loops again

#Print the location of all the cards
def showDeck():
    print("Location of all the cards:\n#      card                   location")
    #Go through every card in deck
    for i in range(NUMCARDS):
        #Card val is index of card in cardLoc, use the index to interpret the suit and value
        cardVal = i
        #Prepare variable for suit name
        thisSuitName = "unknown suit"
        #Check which quadrant of the cards this value is, assign suit name in order from list.
        #suitNum is 13, how many cards per suit
        suitNum = NUMCARDS/len(suitName)
        #Go through 4 times finding what suit it is
        for j in range(len(suitName)):
            #check which quadrant 1/4, 2/4, 3/4, 4/4
            if cardVal < (j+1)*suitNum:
                #If it is, set thisSuitName to the suit
                thisSuitName = suitName[j]
                #Break out when set, or every card will be last suit 'of clubs'
                break
        #Format number left 4 spaces, value left 6 spaces, 'of' suitname 10 spaces, then location
        print("{:<4} {:<6} of {:<10} {}".format(cardVal, rankName[cardVal%13], thisSuitName, playerName[cardLoc[cardVal]]))
    #format self explanatory
    print("\n")

#Display cards specific to a hand
def showHand(playerVal):
    print("Displaying {} hand:".format(playerName[playerVal]))
    #Go through every card
    for i in range(NUMCARDS):
        #If card is located in the hand, basically do same thing in show deck
        if playerVal == cardLoc[i]:
            cardVal = i
            thisSuitName = "unknown suit"
            #This algorithim explained in showCards()
            suitNum = NUMCARDS/len(suitName)
            for j in range(len(suitName)):
                if cardVal < (j+1)*suitNum:
                    thisSuitName = suitName[j]
                    break
            #Format same in showCards() minus player name
            print("{:<4} {:<6} of {:<10}".format(cardVal, rankName[cardVal%13], thisSuitName))
    print("\n")

#Run function
main()
