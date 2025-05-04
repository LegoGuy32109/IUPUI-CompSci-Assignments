package a2.common;

import java.rmi.*;

import java.util.Vector;

public interface StoreImpl extends Remote {
    // return the name variable
	public String getName() throws RemoteException;

	// set the name variable to newName
	public void setName(String newName) throws RemoteException;

	public Vector<Item> getItems() throws RemoteException;
	public boolean setItem(String prevItemDesc, Item newItem) throws RemoteException;
	public void addItem(Item item) throws RemoteException;
	public void deleteItem(String itemDesc) throws RemoteException;
	public Item getItem(Item item) throws RemoteException;

	public User getUser(String userName) throws RemoteException;
	public Vector<User> getUsers() throws RemoteException;
	public void addUser(User newUser) throws RemoteException;
	public void deleteUser(String userName) throws RemoteException;
}
