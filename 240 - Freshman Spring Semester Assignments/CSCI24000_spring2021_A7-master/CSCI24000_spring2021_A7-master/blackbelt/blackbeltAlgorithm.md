### GOALS ###
I would like to expand the functionality of the ATM system so far. I think the ATM should have a certain amount of money that it has, and needs to be refilled so that users can continue getting money out of their accounts. However, making deposits will increase the amount of money the ATM can disperse, because they put money in. 
I also think there should be a User list of Admins, because realistically there would be more than one Admin for the ATM system.
I also think it would be cool if there was some kind of encryption for the data, like the simple crypto assignment. 

### INPUTS ### 
The data file for the Users will be encrypted as well as the Admin log

### OUTPUTS ###
The program will tell how much money is inside of the ATM
The user data and admin data will be saved as an encryption. 

### STEPS ###
Create another User arraylists specifically for Admins, the balances associated can be ignored
generate a random key for each ATM object created that will encrypts it's stuff
give the save and load functions specific parameters for file paths
The encryption needs it's own encode and decode functions, I'll make them private in the ATM class so no one else can get them

The random key will only be generated if an admin from the list of admins says to.

I have to encrpt my data, then save it to the files manually, because the program starts by decrypting then ends by encrypting.
