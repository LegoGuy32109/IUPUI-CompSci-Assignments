package a2.client;

import java.rmi.Naming;
import java.util.Scanner;
import java.util.Vector;

import a2.common.StoreImpl;
import a2.common.User;
import a2.common.Item;

public class Client {

	public static void userMenu(Scanner readObj, User user, StoreImpl store) {
		try {
			boolean menuActive = true;
			if (user.isAdmin()) {
				// admin menu
				while (menuActive){
					System.out.println("Would you like to:");
					System.out.println("[1] - Edit Users");
					System.out.println("[2] - Edit Items");
					System.out.println("[3] - Exit");
					int adminChoice = Integer.parseInt(readObj.nextLine());
					if(adminChoice == 1){
						boolean userMenu = true;
						while(userMenu){
							Vector<User> currentUsers = store.getUsers();
							System.out.println("Delete any of the users below\n===================");
							for(int i = 0; i< currentUsers.size(); i++){
								if(currentUsers.get(i).isAdmin()){
									System.out.println("["+i+"] - Admin: "+currentUsers.get(i).getName());
								}else{
									System.out.println("["+i+"] - User: "+currentUsers.get(i).getName());
								}
							}
							System.out.println("["+currentUsers.size()+"] - Add User");
							System.out.println("["+(currentUsers.size()+1)+"] - Add Admin");
							System.out.println("["+(currentUsers.size()+2)+"] - Exit");
							
							adminChoice = Integer.parseInt(readObj.nextLine());
							// selected account to delete
							if(adminChoice >= 0 && adminChoice < currentUsers.size()){
								if(user.getName().equals(currentUsers.get(adminChoice).getName())){
									System.out.println("You can't remove yourself!");
								}else {
									store.deleteUser(currentUsers.get(adminChoice).getName());
								}
							// creating a new User or Admin
							}else if(adminChoice == currentUsers.size() || adminChoice == currentUsers.size()+1){
								System.out.println("What will be the name of the account?\n: ");
								String newUsername = readObj.nextLine();
								if(adminChoice == currentUsers.size()){
									store.addUser(new User(newUsername, false));
									System.out.println("New User, "+newUsername+", added");
								}else {
									store.addUser(new User(newUsername, true));
									System.out.println("New Admin, "+newUsername+", added");
								}
							// Exiting
							}else if(adminChoice == currentUsers.size()+2){
								userMenu = false;
							}else{
								System.out.println("Didn't understand your input, "+adminChoice+", try again.");
							}
						}
					}else if (adminChoice == 2){
						boolean itemMenu = true;
						while(itemMenu){
							Vector<Item> currentItems = store.getItems();
							System.out.println("Edit any of the items below\n===================");
							for(int i = 0; i< currentItems.size(); i++){
								Item curItem = currentItems.get(i);
								System.out.printf("[%d] - (%d) %s (%.2f)\n", i, curItem.quantity, curItem.desc, curItem.price);
							}
							System.out.println("["+(currentItems.size())+"] - Add Item");
							System.out.println("["+(currentItems.size()+1)+"] - Exit");
							
							adminChoice = Integer.parseInt(readObj.nextLine());
							// editing an item
							if(adminChoice >= 0 && adminChoice < currentItems.size()){
								boolean itemSubmenu = true;
								Item curItem = currentItems.get(adminChoice);
								String prevItemDesc = curItem.desc;
								while(itemSubmenu){
									System.out.println("What would you like to edit for "+curItem.desc+"?");
									System.out.println("[1] - Description");
									System.out.println("[2] - Quantity");
									System.out.println("[3] - Price");
									System.out.println("[4] - DELETE this item");
									adminChoice = Integer.parseInt(readObj.nextLine());
									if(adminChoice == 1){
										System.out.println("Enter the new description for this item: ");
										String newDesc = readObj.nextLine();
										curItem.desc = newDesc;
										itemSubmenu = false;
										
									}else if(adminChoice == 2) {
										System.out.println("Enter the new Quantity for this item: ");
										int newQ = Integer.parseInt(readObj.nextLine());
										curItem.quantity = newQ;
										itemSubmenu = false;
										
									}else if(adminChoice == 3) {
										System.out.println("Enter the new price for this item: ");
										Float newPrice = Float.parseFloat(readObj.nextLine());
										curItem.price = newPrice;
										itemSubmenu = false;

									}else if(adminChoice == 4){
										store.deleteItem(prevItemDesc);
										System.out.println(prevItemDesc+" Deleted");
									}else{
										System.out.println("Didn't understand your input, "+adminChoice+", try again.");
									}
								}
								// update store with newItem
								store.setItem(prevItemDesc, curItem);

							}else if(adminChoice == currentItems.size()){
								System.out.println("Enter the new description for this item: ");
								String newDesc = readObj.nextLine();
								System.out.println("Enter the new Quantity for this item: ");
								int newQ = Integer.parseInt(readObj.nextLine());		
								System.out.println("Enter the new price for this item: ");
								Float newPrice = Float.parseFloat(readObj.nextLine());
								store.addItem(new Item(newDesc, newPrice, newQ));

							// Exiting menu
							}else if(adminChoice == currentItems.size()+1){
								itemMenu = false;
							}else{
								System.out.println("Didn't understand your input, "+adminChoice+", try again.");
							}
						}
					}else if (adminChoice == 3){
						menuActive = false;
					} else {

					}
				}
			} else {
				// customer menu
				Vector<Item> cart = new Vector<Item>();
				while (menuActive) {
					Vector<Item> currentItems = store.getItems();
					System.out.println("\nSelect which item you'd like to purchase!\n========================");
					System.out.println("[0] - Checkout Cart 🛒");
					for (int i = 0; i < currentItems.size(); i++) {
						Item curItem = currentItems.get(i);
						System.out.printf("[%d] - %s (%.2f)\n", i + 1, curItem.desc, curItem.price);
					}
					System.out.println("[" + (currentItems.size() + 1) + "] - EXIT MENU\n: ");
					int input = Integer.parseInt(readObj.nextLine());

					// invalid input choice from menu
					if (input < 0 || input > currentItems.size() + 1) {
						System.out.println("Item " + input + " could not be found.");

						// valid input choice from menu
					} else {
						// Checking out cart
						if (input == 0) {
							if (cart.size() == 0) {
								System.out.println("You don't have any items in your cart, add some!");
							} else {
								float total = 0;
								// check there are enough items in store
								for (int i = 0; i < cart.size(); i++) {
									Item storeItem = store.getItem(cart.get(i));
									total += storeItem.quantity*storeItem.price;
								}
								System.out.printf(
										"You just purchased all the items in your cart! Your total is: %.2f",
										total);
									
								cart.clear(); // unless already empty clear all items
							}

							// exiting shopping menu
						} else if (input == currentItems.size() + 1) {
							menuActive = false;

							// Adding specific Item
						} else {
							Item curItem = store.getItems().get(input - 1);
							if (curItem.quantity == 0) {
								System.out.printf("This item is out of stock, please check back soon!");
							} else {
								System.out.printf("You choose: %s (%.2f), how many would you like to purchase?\n: ",
										curItem.desc, curItem.price);
								boolean choosingQuantity = true;
								while (choosingQuantity) {
									input = Integer.parseInt(readObj.nextLine());
									// valid choice
									if (input > 0 && input <= curItem.quantity) {
										System.out.println(
												"You added " + input + " " + curItem.desc + "(s) to your cart!");
										// add to cart that amount of item
										curItem.quantity = input;
										cart.add(curItem);

										choosingQuantity = false;

										// invalid choice
									} else {
										System.out.println("Your choice " + input
												+ " isn't valid, the current quantity of this item is: "
												+ curItem.quantity);
									}
								}
							}
						}
					}
				}
			}
		} catch (Exception e) {
			System.out.println("Client err in menu: " + e.getMessage());
			e.printStackTrace();
		}
		// menu is no longer active, going back to login
	}

	public static void main(String args[]) {
		try {
			// scanner to recieve user input
			Scanner readObj = new Scanner(System.in);

			// determine when user is done using session
			boolean sessionActive = true;

			// location of RemoteAccount object the client recieves data from
			String name = "//in-csci-rrpc03.cs.iupui.edu:2323/RemoteStore";
			// instance of the RemoteStore to run methods on
			StoreImpl store = (StoreImpl) Naming.lookup(name);

			System.out.println("Connection Established, Welcome to " + store.getName());

			// login screen
			String userName;
			while (sessionActive) {
				System.out.println("Please login or create an account");
				System.out.println("[1] - Login");
				System.out.println("[2] - Register new User");
				System.out.println("[3] - Exit");
				int input = Integer.parseInt(readObj.nextLine());
				switch (input) {
					// check if login exists, if not complain
					case 1:
						System.out.println("Please input your username: ");
						userName = readObj.nextLine();
						User user = store.getUser(userName);
						if (user != null) {
							// activate interactve menu
							userMenu(readObj, user, store);
						} else {
							System.out.println("Could not find user: '" + userName + "'', returning to menu.");
						}
						break;

					// go through new registration process
					case 2:
						boolean userIsNull = true;
						while (userIsNull) {
							System.out.println("Enter your new Username: ");
							userName = readObj.nextLine();
							User newUser = new User(userName);
							System.out.println(store.getUser(userName));
							if (store.getUser(userName) != null) {
								System.out.println("Sorry, that Username is already taken.");
							} else {
								userIsNull = false; // no longer null
								// activate interactive menu
								System.out.println("Nice to meet you " + newUser.getName() + "!");
								store.addUser(newUser);
								userMenu(readObj, newUser, store);
							}
						}
						break;

					// user quits session
					case 3:
						sessionActive = false;
						break;

					// input not understood
					default:
						System.out.println("Your choice was invalid, please try again.");
				}
			}

			System.out.println("Thank you for visiting " + store.getName() + "!");
			readObj.close();
			// end of file, the program ends
		} catch (Exception e) {
			System.out.println("Client err : " + e.getMessage());
			e.printStackTrace();

		}
	}
}
