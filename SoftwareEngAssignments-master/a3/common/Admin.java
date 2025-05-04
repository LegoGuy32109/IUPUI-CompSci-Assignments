/*
 * Admin.java
 * 
 * A child of the User abstract class. Designed to give a view of an Admin menu and preform Admin
 * operations with a FrontController object.
 */

package a3.common;

import java.util.Scanner;
import java.util.Vector;

public class Admin implements User {

    // Name of the admin
    private String name;

    // Default constructor of the Admin
    public Admin() {
        this.name = "default username";
    }

    // Create an Admin with a specific userName
    public Admin(String userName) {
        this.name = userName;
    }

    // Return the Admin's name
    public String getName() {
        return this.name;
    }

    // Set the Admin's name
    public void setName(String newName) {
        this.name = newName;
    }

    // In this child instance of User, activating the menu creates an 
    // Admin menu to interface with
    public void activateMenu(Scanner readObj, FrontController controller) {
        try {
            boolean menuActive = true;
            while (menuActive) {
                System.out.println("Would you like to:");
                System.out.println("[1] - Edit Users");
                System.out.println("[2] - Edit Items");
                System.out.println("[3] - Exit");
                int adminChoice = Integer.parseInt(readObj.nextLine());

                // Admin wants to edit Users
                if (adminChoice == 1) {
                    boolean userMenu = true;
                    while (userMenu) {
                        Vector<User> currentUsers = controller.getUsers();
                        System.out.println("Delete any of the users below\n===================");
                        for (int i = 0; i < currentUsers.size(); i++) {
                            if (currentUsers.get(i) instanceof Admin) {
                                System.out.println("[" + i + "] - Admin: " + currentUsers.get(i).getName());
                            } else {
                                System.out.println("[" + i + "] - Customer: " + currentUsers.get(i).getName());
                            }
                        }
                        System.out.println("[" + currentUsers.size() + "] - Add User");
                        System.out.println("[" + (currentUsers.size() + 1) + "] - Add Admin");
                        System.out.println("[" + (currentUsers.size() + 2) + "] - Exit");

                        adminChoice = Integer.parseInt(readObj.nextLine());

                        // selected account to delete
                        if (adminChoice >= 0 && adminChoice < currentUsers.size()) {
                            if (this.getName().equals(currentUsers.get(adminChoice).getName())) {
                                System.out.println("You can't remove yourself!");
                            } else {
                                controller.deleteUser(currentUsers.get(adminChoice).getName());
                            }

                            // creating a new User or Admin
                        } else if (adminChoice == currentUsers.size() || adminChoice == currentUsers.size() + 1) {
                            // grab userCreators for admin and customer
                            AdminCreator adminCreator = new AdminCreator();
                            CustomerCreator customerCreator = new CustomerCreator();

                            System.out.println("What will be the name of the account?\n: ");
                            String newUsername = readObj.nextLine();

                            // Creating a new User
                            if (adminChoice == currentUsers.size()) {
                                controller.addUser(customerCreator.createUser(newUsername));
                                System.out.println("New Customer, " + newUsername + ", added");

                                // Creating a new Admin
                            } else {
                                controller.addUser(adminCreator.createUser(newUsername));
                                System.out.println("New Admin, " + newUsername + ", added");
                            }
                            // Exiting
                        } else if (adminChoice == currentUsers.size() + 2) {
                            userMenu = false;
                        } else {
                            System.out.println("Didn't understand your input, " + adminChoice + ", try again.");
                        }
                    }

                    // Admin wants to edit Items
                } else if (adminChoice == 2) {
                    boolean itemMenu = true;
                    while (itemMenu) {
                        Vector<Item> currentItems = controller.getItems();
                        System.out.println("Edit any of the items below\n===================");
                        for (int i = 0; i < currentItems.size(); i++) {
                            Item curItem = currentItems.get(i);
                            System.out.printf("[%d] - (%d) %s (%.2f)\n", i, curItem.quantity, curItem.desc,
                                    curItem.price);
                        }
                        System.out.println("[" + (currentItems.size()) + "] - Add Item");
                        System.out.println("[" + (currentItems.size() + 1) + "] - Exit");

                        adminChoice = Integer.parseInt(readObj.nextLine());

                        // editing an item
                        if (adminChoice >= 0 && adminChoice < currentItems.size()) {
                            boolean itemSubmenu = true;
                            Item curItem = currentItems.get(adminChoice);
                            String prevItemDesc = curItem.desc;
                            while (itemSubmenu) {
                                System.out.println("What would you like to edit for " + curItem.desc + "?");
                                System.out.println("[1] - Description");
                                System.out.println("[2] - Quantity");
                                System.out.println("[3] - Price");
                                System.out.println("[4] - DELETE this item");
                                adminChoice = Integer.parseInt(readObj.nextLine());
                                // Editing Desctiption
                                if (adminChoice == 1) {
                                    System.out.println("Enter the new description for this item: ");
                                    String newDesc = readObj.nextLine();
                                    curItem.desc = newDesc;
                                    itemSubmenu = false;

                                    // Editing Quantity
                                } else if (adminChoice == 2) {
                                    System.out.println("Enter the new Quantity for this item: ");
                                    int newQ = Integer.parseInt(readObj.nextLine());
                                    curItem.quantity = newQ;
                                    itemSubmenu = false;

                                    // Editing Price
                                } else if (adminChoice == 3) {
                                    System.out.println("Enter the new price for this item: ");
                                    Float newPrice = Float.parseFloat(readObj.nextLine());
                                    curItem.price = newPrice;
                                    itemSubmenu = false;

                                    // Deleting Item
                                } else if (adminChoice == 4) {
                                    controller.deleteItem(prevItemDesc);
                                    System.out.println(prevItemDesc + " Deleted");
                                    itemSubmenu = false;
                                    
                                } else {
                                    System.out.println("Didn't understand your input, " + adminChoice + ", try again.");
                                }
                            }
                            // update store with newItem
                            controller.setItem(prevItemDesc, curItem);

                            // Chose to create a new Item
                        } else if (adminChoice == currentItems.size()) {
                            System.out.println("Enter the new description for this item: ");
                            String newDesc = readObj.nextLine();
                            System.out.println("Enter the new Quantity for this item: ");
                            int newQ = Integer.parseInt(readObj.nextLine());
                            System.out.println("Enter the new price for this item: ");
                            Float newPrice = Float.parseFloat(readObj.nextLine());
                            controller.addItem(new Item(newDesc, newPrice, newQ));

                            // Exiting menu
                        } else if (adminChoice == currentItems.size() + 1) {
                            itemMenu = false;
                        } else {
                            System.out.println("Didn't understand your input, " + adminChoice + ", try again.");
                        }
                    }

                    // Admin wants to leave Admin menu
                } else if (adminChoice == 3) {
                    menuActive = false;

                    // Input is confusing
                } else {
                    System.out.println("Didn't understand your input, " + adminChoice + ", try again.");
                }
            }
        } catch (Exception e) {
            System.out.println("Client err in admin menu: " + e.getMessage());
            e.printStackTrace();
        }
    }

}
