### GOALS ###
I want to make an ATM system in java. It will load users info from a file and then edit it, and save to the same file when closing. Users will all have a checking account and savings account. An account has a balance that can be deposited into or withdrawn from. You cannot go into debt. A savings account is the same as a checking account but savings will have an interest attribute and a way to calculate the interest with the current ballance for a certain number of months. 
The ATM will have some list full of users, each user has a PIN and account number as well, both integers. When the program runs you are prompted for your account number and PIN. If it has a User object that matches that, a User menu is displayed. If not. the ATM quits and ends the program. If the account number is 00000 and the pin is 12345 an admin menu will show up. Users can deposit, withdraw, and view both of their accounts, as well as quit the ATM. Admins can create Users, delete users (not if they have money in their accounts), list all the Users in the ATM, apply interest to all the accounts in the ATM giving the ATM a period in months to calculate the interest and apply it to their savings balance, and of course leave the atm. 
I will be using custom classes in java to accomplish this. 

### INPUTS ###
At the beginning Users will need to enter their account number and pin to access ATM

If normal User
1. User can input an amount to deposit in their checking or savings
2. User can input an amount to withdraw from their checking or savings
3. User can view balances
4. User can leave ATM

If Admin
1. Admin can add user by typing in new account number and pin
2. Admin can delete user by typing in account number and pin
3. admin can list all users
4. admin can indicate how many months to apply interest to all saving accounts
5. admin can leave atm

### OUTPUTS ###
If user

1. User is shown balances after witdrawing or depositing
2. User is shown balance after choosing to view balance of checking or savings

If Admin

1. Admin is told User is created
2. Admin is told User is deleted, or told why not
3. Admin can view all Users and their balances if chosen to list
4. Admin is told interest of a certain amount of months was applied

Both

When ATM shuts down message is displayed indicating shut down

### STEPS ###
A class should be made for checking called Account, a Savings class can extend from that.
A User class should be made that has Checking and Saving attributes
The atm will have the 'main' program, and contain a list of known Users.

Admin will show up in login method in ATM, if the credentials match admin credentials
knownUsers should be an ArrayList<User> for dynamic editing

students.dat should be file that users are loaded from and saved to
if program crashes students.dat is saved to be an empty file, whoops!

ATM is the biggest thing, writing the menus for users and admins, functionality with the array list
