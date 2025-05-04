/*
 * Client.java
 * 
 * Client component to act as a interface for a bank system user sending
 * messages to the Server and recieving data from the RemoteAccount object.
 */

package a1.client;

import java.rmi.Naming;
import java.util.Scanner;
import java.util.InputMismatchException; // for Input handeling

import a1.common.AccountImpl;

public class Client {
	// function to render menu to user and recieve input
	static int menu(Scanner readObj) {
		System.out.println("Please select an option [1-4] from below.");
		System.out.println("1. Display Current Balance");
		System.out.println("2. Make a deposit");
		System.out.println("3. Make a withdrawl");
		System.out.println("4. Quit Session");
		try {
			return readObj.nextInt();
		} catch (InputMismatchException e) {
			// if input is not an integer, return -1 to notify user it's invalid
			return -1;
		}
	}

	// main function to run the client and recieve user input
	public static void main(String args[]) {
		try {
			// scanner to recieve user input
			Scanner readObj = new Scanner(System.in);
			// keeping track if the program should end, set to false when
			// user quits session.
			boolean sessionActive = true;
			// location of RemoteAccount object the client recieves data from
			String name = "//in-csci-rrpc01.cs.iupui.edu:2323/RemoteAccount";
			// instance of the RemoteAccount to run methods on
			AccountImpl stub = (AccountImpl) Naming.lookup(name);

			System.out.println("Connection to bank established, Welcome " + stub.getName());
			// loop to recieve input from user
			while (sessionActive) {
				// input from the menu rendering function
				int input = menu(readObj);
				switch (input) {

					// Display User's Current Balance
					case 1:
						System.out.println("Client calling server to access balance");
						System.out.println("Got response back from server : " + stub.getBalance());
						break;

					// User is depositing a certain amount of money
					case 2:
						try {
							System.out.println("How much are you depositing?");
							// amount user wishes to deposit
							double amount = readObj.nextDouble();
							stub.deposit(amount);
							System.out.println(amount + " was deposited into your account.");

						} catch (InputMismatchException e) {
							System.out.println("That input is not possible, please try again.");
						}
						break;

					// User is withdrawing a certain amount of money
					case 3:
						try {
							System.out.println("How much are you withdrawing?");
							// amount user wishes to withdraw
							double amount = readObj.nextDouble();
							// if insufficent funds in account, notify user
							if (stub.getBalance() - amount < 0.0) {
								System.out.println("You do not have enough money to make this withdrawl");
							} else {
								stub.withdraw(amount);
								System.out.println(amount + " was withdrawn from your account.");
							}
						} catch (InputMismatchException e) {
							System.out.println("That input is not possible, please try again.");
						}
						break;

					// Exit the session ending the program
					case 4:
						sessionActive = false;
						break;

					// in default case, the imput is not recognized
					default:
						System.out.println("Input " + input + " isn't valid choice, please try again.");
				}
			}
			System.out.println("Thank you for using our system!");
			readObj.close();
			// end of file, the program ends
		} catch (Exception e) {
			System.out.println("Client err : " + e.getMessage());
			e.printStackTrace();

		}
	}

}
