/*
 * Customer.java
 * 
 * A child of the User abstract class. Designed to give a view of a Customer menu 
 * and preform Customer operations with a FrontController object.
 */

package a3.common;

import java.util.Scanner;
import java.util.Vector;

public class Customer implements User {

	// Name of the customer
	private String name;

	// Default constructor of a customer
	public Customer() {
		this.name = "default username";
	}

	// Create a customer with a specific userName
	public Customer(String userName) {
		this.name = userName;
	}

	// Return the Customer's name
	public String getName() {
		return this.name;
	}

	// Set the Customer's name
	public void setName(String newName) {
		this.name = newName;

	}

	// In this child instance of User, activating the menu creates a
	// Customer menu to interface with
	public void activateMenu(Scanner readObj, FrontController controller) {
		try {
			boolean menuActive = true;
			Vector<Item> cart = new Vector<Item>();
			while (menuActive) {
				Vector<Item> currentItems = controller.getItems();
				System.out.println("\nSelect which item you'd like to purchase!\n========================");
				System.out.println("[0] - Checkout Cart 🛒");
				for (int i = 0; i < currentItems.size(); i++) {
					Item curItem = currentItems.get(i);
					System.out.printf("[%d] - %s ($%.2f)\n", i + 1, curItem.desc, curItem.price);
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
								Item storeItem = controller.getItem(cart.get(i));
								total += storeItem.quantity * storeItem.price;
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
						Item curItem = controller.getItems().get(input - 1);
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
									System.out.println("You added " + input + " " + curItem.desc + "(s) to your cart!");
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
		} catch (Exception e) {
			System.out.println("Client err in customer menu: " + e.getMessage());
			e.printStackTrace();
		}
	}

}
