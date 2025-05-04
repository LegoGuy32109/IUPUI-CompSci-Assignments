/*
 * AccountImpl.java
 * 
 * An interface of a remote object for Accounts in the bank system. 
 * The client can understand it's functions without containing information
 * on the operations of the implemented class RemoteAccount.java
 */

package a1.common;

import java.rmi.*;

public interface AccountImpl extends Remote {
	// return the name variable
	public String getName() throws RemoteException;

	// set the name variable to newName
	public void setName(String newName) throws RemoteException;

	// return the Money variable balance
	public double getBalance() throws RemoteException;

	// set the Money variable balance to newBalance
	public void setBalance(double newBalance) throws RemoteException;

	// withdraw the parameter amount from the variable Money amount
	public void withdraw(double amount) throws RemoteException;

	// deposit the parameter amount into the variable Money amount
	public void deposit(double amount) throws RemoteException;
}
