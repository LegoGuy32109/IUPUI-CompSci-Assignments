""" crypto.py
    Implements a simple substitution cypher
    Josh Hale is editing this
"""

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
key = "XPMGTDHLYONZBWEARKJUFSCIQV"

#Main function starts here, professor gave it to us I didn't touch it
def main():
    keepGoing = True
    while keepGoing:
#Print menu and get response when acceptable input is given
        response = menu()
        if response == "1":
#recieve input text
            plain = input("text to be encoded: ")
#print what encode returns with 'plain'
            print(encode(plain))
        elif response == "2":
#recieve coded text
            coded = input("code to be decyphered: ")
#print what decode returns with 'coded'
            print (decode(coded))
        elif response == "0":
            print ("Thanks for doing secret spy stuff with me.")
#Stop loop, program ends
            keepGoing = False
#the way I wrote it this never runs, my menu() only returns 1, 2, 0
        else:
            print ("I don't know what you want to do...")

#called to display menu and return correct input
def menu():
#This loop runs until it returns
    while True:
#Display options
        print(" SECRET DECODER MENU\n\n0) Quit\n1) Encode\n2) Decode\n\n What do you want to do?")
#Accept input
        userResp = input()
#Make sure input is one of these 3
        if(userResp == "1" or userResp == "2" or userResp == "0"):
#it's corrent, return the right stuff 1,2, or 0
            return userResp
        else:
#User didn't input one of the 3, tell them they're wrong
            print("Sorry I can't understand that..\n")

#encode function with paramater plain, to change each character to the index in key then return it.
def encode(plain):
#set plain to uppercase
    plain = plain.upper()
#declare output as empty string to have code put into it
    out = ""
#loop through every character in input
    for letter in plain:
#find the index of the character in alpha, and find the value in key at that index. Add that to out
        if(alpha.find(letter)==-1):
            continue
        out+=key[alpha.find(letter)]
#return out
    return out

#very similar to encode, with coded as the parameter
def decode(coded):
#set coded to uppercase incase user didn't
    coded = coded.upper()
#set plain to an empty string to return decoded output
    plain = ""
#loop through every character in the coded input
    for letter in coded:
#same thing in decode just replace alpha and key
        plain += alpha[key.find(letter)]
#set plain to lowercase, then capitalzie the first letter for niceness
        plain = (plain.lower()).capitalize()
#return decoded input
    return plain

#Run the program here, after all functions are defined
main()
