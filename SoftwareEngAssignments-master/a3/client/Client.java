/*
 * Client.java
 * 
 * Client component to act as a interface for a Store system. User sends
 * messages and recieves data from the RemoteStore object.
 */

package a3.client;

import java.rmi.Naming;
import java.util.Scanner;

import a3.common.StoreImpl;
import a3.common.User;
import a3.common.AdminCreator;
import a3.common.CustomerCreator;
import a3.common.FrontController;

public class Client {

	public static void main(String args[]) {
		try {
			// scanner to recieve user input
			Scanner readObj = new Scanner(System.in);

			// determine when user is done using session
			boolean sessionActive = true;

			// location of RemoteAccount object the client recieves data from
			String name = "//in-csci-rrpc03.cs.iupui.edu:2324/RemoteStore";
			// instance of the RemoteStore to run methods on
			StoreImpl store = (StoreImpl) Naming.lookup(name);

			// Create user creators for User registartion, Customer or Admin
			CustomerCreator customerCreator = new CustomerCreator();
			AdminCreator adminCreator = new AdminCreator();

			// FrontController to dispach commands to
			FrontController controller = new FrontController(store);

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
					
						if (controller.isUserAuthenticated(userName)) {
							// activate interactve menu
							controller.getUser(userName).activateMenu(readObj, controller);
						} else {
							System.out.println("Could not find user: '" + userName + "'', returning to menu.");
						}
						break;

					// go through new registration process
					case 2:
						// this will be overwritten
						User newUser = customerCreator.createUser("defaultUser"); 
						
						boolean userIsNull = true;
						while (userIsNull) {
							System.out.println("Enter your new Username: ");
							userName = readObj.nextLine();
							if (controller.isUserAuthenticated(userName)) {
								System.out.println("Sorry, that Username is already taken.");
							} else {
								userIsNull = false; // no longer null

								// A new User is being created, specify if it's an Admin or Customer
								boolean userTypeChoice = true;
								while (userTypeChoice) {
									System.out.println(
											"Are you an Administrator or Customer? (Admins cannot purchase Items)");
									System.out.println("[1] - Customer");
									System.out.println("[2] - Admin");
									int userType = Integer.parseInt(readObj.nextLine());
									if (userType == 1) {
										newUser = customerCreator.createUser(userName);
										userTypeChoice = false;
									} else if (userType == 2) {
										newUser = adminCreator.createUser(userName);
										userTypeChoice = false;
									} else {
										System.out.println("Sorry, I didn't understand you, please try again.");
									}
								}

								// add whichever type of user this is to the store
								controller.addUser(newUser); 

								// Activate interactive menu for that User
								System.out.println("Nice to meet you " + newUser.getName() + "!");
								newUser.activateMenu(readObj, controller);
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
