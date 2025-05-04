#This program written by Josh Hale for change.py Black Belt assignment

#variable created to store user input and check if it can be integer/float
userInput = ""
#price variable created to store cost of items
price = 0
#vending machine object created with the label as the food item and the values as the prices in dollars. I designed the list for every 5 items to be similar, they would be on the same row of a vending machine
vendingMachine = {
    "Doritos": 2.49,
    "Cheetos": 1.99,
    "Lays Classic":1.49,
    "Lays Barbeque":1.49,
    "Munchies": 1.74,
    "Warheads":1.19,
    "Jawbreakers":1.49,
    "Gobstoppers":1.59,
    "Sour Patch Kids":2.49,
    "Sweedish Fish":1.99,
    "Mint Gum":0.49,
    "Bubble Gum":0.39,
    "Hubble Bubble Gum":0.69,
    "Altoids":0.49,
    "Tootsie Roll":0.31,
}

#index to keep track of IDs of the items in the loop
index = 0
#prices dictonary created that will be populated with data from the vendingMachine as well as their IDs
prices={}
#letter to begin the IDs with, in this case A for A1, A2...
IDLetter = "A"
#Flex all the num of options to the user
print("Welcome to the JMart Vending Machine with it's fabulous {} options!".format(len(vendingMachine)))
#Go through every item in the vendingMachine
for key in vendingMachine:
#keep track of index for ID
    index+=1
#Every 6th item have the IDLetter go to the next one, A to B
    if(index%6==0):
#Find current IDLetter and make the ASCII value go up by one, so the letters increment
        IDLetter = chr(ord(IDLetter)+1)
#reset index value for next row, the IDS should start with 1
        index-=5
#Display the item for the user, ex: B4, Sour Patch Kids: 2.49
    print("{}{}, {}: {}".format(IDLetter,index,key,vendingMachine[key]))
#Create an item in the prices dictonary with the ID as the key, and the value an array with the price and the name of the item
    prices[IDLetter+str(index)]=[vendingMachine[key],key]

# print(prices)

# continue going until the user types end
while userInput != "end":
#to check if a valid ID was entered
    inputSuccess = False
#prompt user indicating their options and how to quit
    userInput = input("Please enter ID (ex. A1) of desired item...('end' to quit)\n: ")
#check if its an end, just leave
    if(userInput.lower()=="end"):
        break

#loop through the prices dict with key and value
    for key, value in prices.items():
#change the input to upper case and see if it matches the key (ID)
        if(userInput.upper()==key):
#Add that to cart, rounding to avoid weird computer math
            price = round(price+value[0],2)
#tell user what they did
            print("You added {} (${}) to cart! Current price is $ {}.".format(value[1],value[0],price))
#show the loop hit a successful ID, so that the error message at end won't show
            inputSuccess = True
#error message if ID doesnt match
        if(not inputSuccess):
            print("Whoops! {} is not a valid ID for this vending machine, try again!".format(userInput.upper()))

#Indicate sum from their items
print("Shopping is over, your total is ${}".format(price))

#Assign the payment variable to store the customer's payment
payment = 0.0
#The loop is very similar to the first while loop, except if statements to confirm the payment is enough to cover the price
while payment == 0.0:
    userInput = input("Please enter the payment\n: ")
    try:
        payment = int(userInput)
        payment = round(float(userInput)/100.0,2)
        print("Found integer, coverting to float...", payment)
#Check if payment covers price here
        if(payment-price<0):
#Set value to 0.0 so loop continues
            payment = 0.0
#Tell user the issue
            print("Not enough payment! Try again...")
#iterate to the next run of the while loop, doesn't break out but goes to top of the loop and repeats
            continue
        break
    except ValueError:
        try:
            payment = round(float(userInput),2)
#same deal from earlier check
            if(payment-price<0):
                payment = 0.0
                print("Not enough payment! Try again...")
                continue
            break
        except ValueError:
            print("Input is not a number. It's a string")
#These print statements symbolize a subtraction problem, big number on top little number on bottom.
print("Payment: ${}".format(payment))
print("Price: ${}".format(price))

#calculate change and round to accomodate weird computer math, assign to change variable
change = round(payment-price, 2)
#print here indicates result of earlier displayed subtraction problem
print( "Change left ${}".format(change))

#NOW THE FUN BEGINS the change value is a float to 2 decimal places, so multiply by 100 and change it to an integer. That represents the number of pennies or the price in cents
pennies = int(change*100)

#This dictionary needs to be in this order, the highest value bill/coin to the least. The keys or labels of the dictonary are displayed in the print statement after the calculation in the loop below.
billsNCoins = {
    "Twenties":2000,
    "Tens":1000,
    "Fives":500,
    "Ones":100,
    "Quarters":25,
    "Dimes":10,
    "Nickels":5,
    "Pennies":1
}

#iterate through every key in the billsNCoins dictonary
for key in billsNCoins:
#set variable amount to an integer that is the quotient of the current amount of pennies by the value from that key in the dictonary. The first case is '2000'. The result is a decimal usually, so it must be turned into an int so remainder is cut off
    amount = int(pennies/billsNCoins[key])
#indicate how many 'Twenties' and so on should be given as change back. Make sure amount is string so it goes into print statment
    print(key+": "+str(amount))
#pennies now becomes the remainder of it's earlier quotient, technically doing the same calculation again but focusing on the remainder instead, this is assigned to the pennies var for the next loop iteration
    pennies %= billsNCoins[key]
#note, the last loop through has pennies %= 1 which sets pennies to 0, and prints to the screen how many pennies should be given to the customer.

#Little message to make it cool and epic
print("\nThanks for using the JoshMart Vending Machine! :)")
