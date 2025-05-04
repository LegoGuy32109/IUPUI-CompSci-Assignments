/*
 * FrontController.java
 * 
 * A class to operate the FrontController design pattern, and dispatch messages and
 * commands to the remoteStore. Will check if the User exists and is authenticated 
 * before accessing menus.
 */

package a3.common;

import java.util.Vector;

public class FrontController {
    // A reference to the remoteStore to dispach commands to
    private StoreImpl remoteStore;

    // A FrontController can only be created with a reference to a remoteStore
    public FrontController(StoreImpl remoteStore) {
        this.remoteStore = remoteStore;
    }

    // check if a user's credentials is authenticated in the store system
    public boolean isUserAuthenticated(String userName) {
        try {
            Vector<User> currentUsers = remoteStore.getUsers();
            for (int i = 0; i < currentUsers.size(); i++) {
                if (currentUsers.get(i).getName().equals(userName)) {
                    return true;
                }
            }
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
        return false;
    }

    // return a list of the current users in the store system
    public Vector<User> getUsers() {
        try {
            return remoteStore.getUsers();
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
        return null;
    }

    // get a user with a certain userName from the store system
    public User getUser(String userName) {
        try {
            Vector<User> currentUsers = remoteStore.getUsers();
            for (int i = 0; i < currentUsers.size(); i++) {
                if (currentUsers.get(i).getName().equals(userName)) {
                    return currentUsers.get(i);
                }
            }
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
        return null;
    }

    // delete a user from the store system
    public void deleteUser(String userName) {
        try {
            Vector<User> currentUsers = remoteStore.getUsers();
            for (int i = 0; i < currentUsers.size(); i++) {
                if (currentUsers.get(i).getName().equals(userName)) {
                    currentUsers.remove(i);
                }
            }
            remoteStore.setUsers(currentUsers); // overwrite store Users with new list
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
    }

    // add a user to the store system
    public void addUser(User newUser) {
        try {
            Vector<User> currentUsers = remoteStore.getUsers();
            currentUsers.add(newUser);
            remoteStore.setUsers(currentUsers); // overwrite store Users with new list
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
    }

    // get a current list of items from the store system
    public Vector<Item> getItems() {
        try {
            return remoteStore.getItems();
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
        return null;
    }

    // get a certain item from the store system
    public Item getItem(Item item) {
        try {
            Vector<Item> currentItems = remoteStore.getItems();
            for (int i = 0; i < currentItems.size(); i++) {
                if (currentItems.get(i).desc.equals(item.desc)) {
                    return item;
                }
            }
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
        return null;
    }

    // set a certain item with a prevItemDesc to be a new Item
    public Item setItem(String prevItemDesc, Item newItem) {
        try {
            Vector<Item> currentItems = remoteStore.getItems();
            for (int i = 0; i < currentItems.size(); i++) {
                if (currentItems.get(i).desc.equals(prevItemDesc)) {
                    currentItems.set(i, newItem);
                }
            }
            remoteStore.setItems(currentItems);
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
        return null;
    }

    // add an Item to the store system
    public void addItem(Item item) {
        try {
            Vector<Item> currentItems = remoteStore.getItems();
            currentItems.add(item);
            remoteStore.setItems(currentItems);
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
    }

    // delete an Item from the store system
    public void deleteItem(String itemDesc) {
        try {
            Vector<Item> currentItems = remoteStore.getItems();
            for (int i = 0; i < currentItems.size(); i++) {
                if (currentItems.get(i).desc.equals(itemDesc)) {
                    currentItems.remove(i);
                }
            }
            remoteStore.setItems(currentItems);
        } catch (Exception e) {
            System.out.println("FrontController err : " + e.getMessage());
            e.printStackTrace();
        }
    }
}
