# Assigment 3

## Setup

1. Login to **in-csci-rrpc03.cs.iupui.edu**
2. Navigate to assignment3 directory
3. Run `rmiregistry 2324 &` *(I couldn't get it to work on rrpc01 or port 2323)*
4. Run `make serverRun`
   a. This generates a jar file if not already, and runs the server side
5. Login to another rrpc like **in-csci-rrpc02.cs.iupui.edu**
6. Navigate to assignment3 directory
7. Run `make clientRun`
   a. This generates a jar file if not already, and runs the client side
8. The login screen should activate on this session

**If the jar file doesn't work, `make clean` then run the command again.**

## Outline

- [README.md](README.md)
- [Assignment #3 Report.md](Assignment3Report.md)
- [Domain_Model_And_Class_Diagram.png](Domain_Model_And_Class_Diagram.png)
- [makefile](makefile)
- A3.jar
- a3
  - client
    - [Client.java](a3/client/Client.java)
  - common
    - [Admin.java](a3/common/Admin.java)
    - [AdminCreator.java](a3/common/AdminCreator.java)
    - [Customer.java](a3/common/Customer.java)
    - [CustomerCreator.java](a3/common/CustomerCreator.java)
    - [FrontController.java](a3/common/FrontController.java)
    - [Item.java](a3/common/Item.java)
    - [StoreImpl.java](a3/common/StoreImpl.java)
    - [User.java](a3/common/User.java)
    - [UserCreator.java](a3/common/UserCreator.java)
  - store
    - [RemoteStore.java](a3/store/RemoteStore.java)
    - [Server.java](a3/store/Server.java)
