""" cardGame.py
basic card game framework
keeps track of card locations for as many hands as needed

functions not main written by Josh Hale
"""
import random

NUMCARDS = 52
DECK = 0
PLAYER = 1
COMP = 2

cardLoc = [0] * NUMCARDS
suitName = ("hearts", "diamonds", "spades", "clubs")
rankName = ("Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
"Ten", "Jack", "Queen", "King")
playerName = ("deck", "player", "computer")
def main():
    clearDeck()

    for i in range(5):
        assignCard(PLAYER)
        assignCard(COMP)

    showDeck()
    showHand(PLAYER)
    showHand(COMP)

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
            break
        #If the if statement didn't work, program loops again

#Print the location of all the cards
def showDeck():
    print("Location of all the cards:\n#    card                      location")
    #Go through every card in deck
    for i in range(NUMCARDS):
        #Card val is index of card in cardLoc, use the index to interpret the suit and value
        cardVal = i
        #Prepare variable for suit name
        thisSuitName = "unknown suit"
        #Check which quadrant of the cards this value is, assign suit name in order from list.
        """
        # if cardVal < (NUMCARDS/4):
        # thisSuitName = suitName[0]
        # elif cardVal < (NUMCARDS/2):
        # thisSuitName = suitName[1]
        # elif cardVal < (3*NUMCARDS/4):
        # thisSuitName = suitName[2]
        # #NUMCARDS is 52 card val only gets to 51
        # elif cardVal < NUMCARDS:
        # thisSuitName = suitName[3]
        Old code replaced below for dynamically changing suits from suitName list
        """
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

""" Need these functions:
clearDeck()
reset card values, every card is in deck. Sets up cardLoc with the values of every
card, which is an integer that contains where it is (all in deck at start), what
rank it is (Ace, two ... king) and the suit name.
52 cards, 1...52. Those numbers can tell what value and suit the card is but not
location. Keep track with index

assignCard(whichPlayer)
randomly draw a card from deck's potential cards, and assign that card to whichever
player specified
(assuming assignCard(DECK) is not used)

showDeck()
print all values in deck, including cards in players hands.

showHand(whichPlayer)
print all cards in certain players hands, can specify deck
"""
