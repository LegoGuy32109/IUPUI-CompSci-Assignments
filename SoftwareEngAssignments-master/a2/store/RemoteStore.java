package a2.store;

import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;

import a2.common.Item;
import a2.common.StoreImpl;
import a2.common.User;

import java.rmi.RemoteException;

public class RemoteStore extends UnicastRemoteObject implements StoreImpl {
	// Inheriting the RemoteStore constructor to throw RemoteExceptions
	// and revieve method definitions from it's interface
	RemoteStore() throws RemoteException {
		super();
	}

	// name of store
	private String name = "[Store]";

	public Vector<Item> itemList = new Vector<Item>();
	public Vector<User> userList = new Vector<User>();

	public Vector<Item> getItems() {
		return itemList;
	}

	public Item getItem(Item item) {
		for (int i = 0; i < itemList.size(); i++) {
			if (itemList.get(i).desc.equals(item.desc)) {
				return item;
			}
		}
		return null;
	}

	public boolean setItem(String prevItemDesc, Item newItem) {
		for (int i = 0; i < itemList.size(); i++) {
			if (itemList.get(i).desc.equals(prevItemDesc)) {
				System.out.println("Item set: " + newItem.desc);
				itemList.set(i, newItem);
				return true;
			}
		}
		return false;
	}

	public void addItem(Item item) {
		if (itemList.add(item)) {
			System.out.println(item.desc + " added.");
		} else {
			System.out.println("Error adding: " + item.desc);
		}
	}

	public void deleteItem(String itemDesc) {
		for (int i = 0; i < itemList.size(); i++) {
			if (itemList.get(i).desc.equals(itemDesc)) {
				System.out.println("Item deleted: " + itemDesc);
				itemList.remove(i);
			}
		}
	}

	// return the name variable
	public String getName() {
		return this.name;
	};

	// set the name variable to newName
	public void setName(String newName) {
		this.name = newName;
	};

	public Vector<User> getUsers() {
		return userList;
	}

	public User getUser(String userName) {
		for (int i = 0; i < userList.size(); i++) {
			if (userList.get(i).getName().equals(userName)) {
				return userList.get(i);
			}
		}
		return null;
	}

	public void deleteUser(String userName) {
		for (int i = 0; i < userList.size(); i++) {
			if (userList.get(i).getName().equals(userName)) {
				userList.remove(i);
			}
		}
	}

	public void addUser(User newUser) {
		// the userName is not found, return the new user.
		userList.add(newUser);
		System.out.println(newUser.getName() + " added as a user, " + userList.size() + " total users.");
	}
}
