/*
 * RemoteStore.java
 * 
 * An implementation of the StoreImpl.java interface to function
 * as a remote object for a client of the store system. 
 */

package a3.store;

import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;

import a3.common.Item;
import a3.common.StoreImpl;
import a3.common.User;

import java.rmi.RemoteException;

public class RemoteStore extends UnicastRemoteObject implements StoreImpl {
	// Inheriting the RemoteStore constructor to throw RemoteExceptions
	// and derive method definitions from it's interface
	RemoteStore() throws RemoteException {
		super();
	}

	// name of store
	private String name = "[Store]";

	// Lists of the items and users
	public Vector<Item> itemList = new Vector<Item>();
	public Vector<User> userList = new Vector<User>();

	// return the name variable
	public String getName() {
		return this.name;
	};

	// set the name variable to newName
	public void setName(String newName) {
		this.name = newName;
	};

	// return the list of items
	public Vector<Item> getItems() {
		return itemList;
	}

	// set the list of items
	public void setItems(Vector<Item> items) {
		this.itemList = items;
	}

	// return the list of users
	public Vector<User> getUsers() {
		return userList;
	}

	// set the list of users
	public void setUsers(Vector<User> userList) {
		this.userList = userList;
	}

}
