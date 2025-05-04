# Assignment 3 Report

## New classes

Of the new classes I have written, many of them are from splitting up the Users into a child classes inheriting from an abstract User class. I also have a UserCreator interface that provides classes for the Creation of both User types, Customer and Admin.

The two types are used instead of one, since the concerns of each are so seperated and don't need to be within the same class. I use the abstract User class to list them together in the store system, but when you're a Customer you don't even need the option for admin stuff and the same goes for Admin users. Each child of User has a `activateMenu()` method for rendering the interface for the user. The Admin and Customer classes add functionality to that class rendering a shopping list and administration options respectively.

I also added the FrontController class, as a object that can dispatch commands from the client to the remoteStore. It also authenticates users confirming their existance is valid in the store system, which then indicates it's apporpriate for the Client to proceed.

## Transition from Assignment #2 to #3

A general theme updating Assignment #2 was removing so much functionality from the `Client.java` class. I had both Admin and Customer menus funcionality in that class which made it huge, and now looks much more manageable thanks to refactoring the menu rendering to User child classes. It evens out the load, and sperates concerns for more effective development.

I'm also glad to remove some functionality in `RemoteStore.java` as there were a lot of logic checks being done to approve Item and User updates. Now, FrontController takes care of that and focuses on updating and confirming correct edits then sends them through to remoteStore to be enacted. A smaller file to look through in RemoteStore helps with seperating concerns for server connection, and internal system logic.

## Sample Runs

### User Signup and purchasing Items

```text
joshhale@in-csci-rrpc02:~$ make clientRun
javac ./a3/client/Client.java
java -cp A3.jar a3/client/Client
Connection Established, Welcome to [Store]
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
2
Enter your new Username:
Josh
null
Are you an Administrator or Customer? (Admins cannot purchase Items)
[1] - Customer
[2] - Admin
1
Nice to meet you Josh!

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
1
You choose: Apple (1.20), how many would you like to purchase?
: 2
You added 2 Apple(s) to your cart!

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
2
You choose: Banana (3.40), how many would you like to purchase?
: 1
You added 1 Banana(s) to your cart!

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
4
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
3
Thank you for visiting [Store]!
```

### User login and purchasing too many items

```text
joshhale@in-csci-rrpc02:~$ make clientRun
java -cp A3.jar a3/client/Client
Connection Established, Welcome to [Store]
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
1
Please input your username:
Josh

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
3
You choose: Baking Powder (6.12), how many would you like to purchase?
: 4
You added 4 Baking Powder(s) to your cart!

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
1
You choose: Apple (1.20), how many would you like to purchase?
: 5
You added 5 Apple(s) to your cart!

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
2
You choose: Banana (3.40), how many would you like to purchase?
: 23
Your choice 23 isn't valid, the current quantity of this item is: 12
2
You added 2 Banana(s) to your cart!

Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
0
You just purchased all the items in your cart! Your total is: 37.28
Select which item you'd like to purchase!
========================
[0] - Checkout Cart 🛒
[1] - Apple ($1.20)
[2] - Banana ($3.40)
[3] - Baking Powder ($6.12)
[4] - EXIT MENU
:
4
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
3
Thank you for visiting [Store]!
```

### Admin logging in, and editing Users

```text
joshhale@in-csci-rrpc02:~$ make clientRun
java -cp A3.jar a3/client/Client
Connection Established, Welcome to [Store]
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
1
Please input your username:
admin
Would you like to:
[1] - Edit Users
[2] - Edit Items
[3] - Exit
1
Delete any of the users below
===================
[0] - Admin: admin
[1] - Customer: Josh
[2] - Add Customer
[3] - Add Admin
[4] - Exit
3
What will be the name of the account?
:
admin2
New Admin, admin2, added
Delete any of the users below
===================
[0] - Admin: admin
[1] - Customer: Josh
[2] - Admin: admin2
[3] - Add Customer
[4] - Add Admin
[5] - Exit
2
Delete any of the users below
===================
[0] - Admin: admin
[1] - Customer: Josh
[2] - Add Customer
[3] - Add Admin
[4] - Exit
0
You can't remove yourself!
Delete any of the users below
===================
[0] - Admin: admin
[1] - Customer: Josh
[2] - Add Customer
[3] - Add Admin
[4] - Exit
4
Would you like to:
[1] - Edit Users
[2] - Edit Items
[3] - Exit
3
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
3
Thank you for visiting [Store]!
```

### Admin logging in and editing Items

```text
joshhale@in-csci-rrpc02:~$ make clientRun
java -cp A3.jar a3/client/Client
Connection Established, Welcome to [Store]
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
1
Please input your username:
admin
Would you like to:
[1] - Edit Users
[2] - Edit Items
[3] - Exit
2
Edit any of the items below
===================
[0] - (5) Apple (1.20)
[1] - (12) Banana (3.40)
[2] - (7) Baking Powder (6.12)
[3] - Add Item
[4] - Exit
1
What would you like to edit for Banana?
[1] - Description
[2] - Quantity
[3] - Price
[4] - DELETE this item
2
Enter the new Quantity for this item:
5
Edit any of the items below
===================
[0] - (5) Apple (1.20)
[1] - (5) Banana (3.40)
[2] - (7) Baking Powder (6.12)
[3] - Add Item
[4] - Exit
3
Enter the new description for this item:
Baked Beans
Enter the new Quantity for this item:
8
Enter the new price for this item:
6.05
Edit any of the items below
===================
[0] - (5) Apple (1.20)
[1] - (5) Banana (3.40)
[2] - (7) Baking Powder (6.12)
[3] - (8) Baked Beans (6.05)
[4] - Add Item
[5] - Exit
2
What would you like to edit for Baking Powder?
[1] - Description
[2] - Quantity
[3] - Price
[4] - DELETE this item
4
Baking Powder Deleted
Edit any of the items below
===================
[0] - (5) Apple (1.20)
[1] - (5) Banana (3.40)
[2] - (8) Baked Beans (6.05)
[3] - Add Item
[4] - Exit
4
Would you like to:
[1] - Edit Users
[2] - Edit Items
[3] - Exit
3
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
3
Thank you for visiting [Store]!
```

### Admin registration, attempt with existing Username

```text
joshhale@in-csci-rrpc02:~$ make clientRun
java -cp A3.jar a3/client/Client
Connection Established, Welcome to [Store]
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
2
Enter your new Username:
admin
Sorry, that Username is already taken.
Enter your new Username:
admin2
Are you an Administrator or Customer? (Admins cannot purchase Items)
[1] - Customer
[2] - Admin
2
Nice to meet you admin2!
Would you like to:
[1] - Edit Users
[2] - Edit Items
[3] - Exit
1
Delete any of the users below
===================
[0] - Admin: admin
[1] - Admin: admin2
[2] - Add Customer
[3] - Add Admin
[4] - Exit
2
What will be the name of the account?
:
Steve
New Customer, Steve, added
Delete any of the users below
===================
[0] - Admin: admin
[1] - Admin: admin2
[2] - User: Steve
[3] - Add User
[4] - Add Admin
[5] - Exit
5
Would you like to:
[1] - Edit Users
[2] - Edit Items
[3] - Exit
3
Please login or create an account
[1] - Login
[2] - Register new User
[3] - Exit
3
Thank you for visiting [Store]!
```
