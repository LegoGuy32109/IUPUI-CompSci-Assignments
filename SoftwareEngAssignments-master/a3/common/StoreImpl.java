/*
 * StoreImpl.java
 * 
 * An interface of a remote object for a Store in the system. 
 * The client can understand it's functions without containing information
 * on the operations of the implemented class RemoteStore.java
 */

package a3.common;

import java.rmi.*;

import java.util.Vector;

public interface StoreImpl extends Remote {
	// return the name variable
	public String getName() throws RemoteException;

	// set the name variable to newName
	public void setName(String newName) throws RemoteException;

	// getters and setters for Item list in Store
	public Vector<Item> getItems() throws RemoteException;

	public void setItems(Vector<Item> items) throws RemoteException;

	// getters and setters for User list in Store
	public Vector<User> getUsers() throws RemoteException;

	public void setUsers(Vector<User> userList) throws RemoteException;
}
