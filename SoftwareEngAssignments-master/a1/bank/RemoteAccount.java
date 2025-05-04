/*
 * RemoteAccount.java
 * 
 * An implementation of the AccountImpl.java interface to function
 * as a remote object for a client of the bank system. 
 */

package a1.bank;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

import a1.common.AccountImpl;
import a1.common.Money;

public class RemoteAccount extends UnicastRemoteObject implements AccountImpl {
	// Inheriting the RemoteAccount constructor to throw RemoteExceptions
	// and revieve method definitions from it's interface
	RemoteAccount() throws RemoteException {
		super();
	}

	// name of the owner of the Account
	private String name = "John Raymond";
	// Money varaible containing the double of the amount of funds in the account
	private Money balance = new Money();

	// return the name variable
	public String getName() {
		return this.name;
	};

	// set the name variable to newName
	public void setName(String newName) {
		this.name = newName;
	};

	// return the Money variable balance
	public double getBalance() {
		return this.balance.amount;
	};

	// set the Money variable balance to newBalance and round and serialize
	public void setBalance(double newBalance) {
		this.balance.amount = newBalance;
		// round the amount to two decimal places to represent pennies
		this.balance.amount = Math.round(this.balance.amount * 100.0) / 100.0;
		// serializing money for data persistance
		this.balance.saveToFile();
	};

	// withdraw the parameter amount from the variable Money amount
	public void withdraw(double amount) {
		setBalance(this.balance.amount - amount);
	}

	// deposit the parameter amount into the variable Money amount
	public void deposit(double amount) {
		setBalance(this.balance.amount + amount);
	}
}
