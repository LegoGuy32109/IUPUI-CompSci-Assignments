#This program written by Josh Hale for change.py assignment
#variable created to store user input and check if it can be integer/float
userInput = ""
#initial price value created
price = 0.0
#loop to make sure input is correct, when price variable is successfully changes the loop ends
while price == 0.0:
#prompt and store the input in userInput
    userInput = input("Please enter the price\n: ")
#attempt this line of code, if an error is thrown when trying to interpret the
    input as an integer, go the the except clause
    try:
#this is the statement that would throw an error if the input cant be found as an int
        price = int(userInput)
#the program needs a float to display the price, so giving an integer it assumes its typing in the amount of cents the price is. Rounds to two decimals in case computer math breaks
        price = round(float(userInput)/100.0,2)
#tell the user what the the program is assuming the price is
        print("Found integer, coverting to float...", price)
#get out of the while loop here, the price variable has changed
        break
#the input cannot be interpreted as an integer, it's either a string or (hopefully) a float
    except ValueError:
#attempt to interpret input as a float, similar to above example
        try:
            price = float(userInput)
#if it is, this while loop ends, the program has a price
            break
#already proven to not be a integer, it's not a double, must be a useless string to the program
        except ValueError:
#indicate error to user
            print("Input is not a number. It's a string")
#the loop repeats, until acceptable input is found and assigned to price

#Indicate the price to user
print("Price: ${}".format(price))
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
print("\nThanks for using JoshMart brand change system! :)")

""" code that I am expected to write, to prove I understand sequential algorithims.
I prefer the option above because it's less code lol.
"""
"""
amount = 0
if pennies>2000:
    amount = int(pennies/2000)
    pennies -= amount * 2000
    print("Twenties: {}".format(amount))
if pennies>1000:
    amount = int(pennies/1000)
    pennies -= amount * 1000
    print("Tens: {}".format(amount))
if pennies>500:
    amount = int(pennies/500)
    pennies -= amount * 500
    print("Fives: {}".format(amount))
if pennies>100:
    amount = int(pennies/100)
    pennies -= amount * 100
    print("Ones: {}".format(amount))
if pennies>25:
    amount = int(pennies/25)
    pennies -= amount * 25
    print("Quarters: {}".format(amount))
if pennies>10:
    amount = int(pennies/10)
    pennies -= amount * 10
    print("Dimes: {}".format(amount))
if pennies>5:
    amount = int(pennies/5)
    pennies -= amount * 5
    print("Nickels: {}".format(amount))
if pennies>0:
    print("Pennies: {}".format(pennies))
"""
