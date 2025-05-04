/*
 * Server.java
 * 
 * The server component recieving messages from a client, hosting the
 * RemoteAccount object for the bank system.
 */

package a1.bank;

import java.rmi.*;

import a1.common.AccountImpl;

public class Server {

	// main method to run the server
	public static void main(String args[]) {
		try {
			// the RemoteAccount object
			AccountImpl remote_acc = new RemoteAccount();
			// name is the server address of where the remoteAccount object
			// is binded to and where the client finds it.
			String name = "//in-csci-rrpc01.cs.iupui.edu:2323/RemoteAccount";
			Naming.rebind(name, remote_acc);
			System.out.println(name);
			System.out.println("Bank Server is ready");

		} catch (Exception e) {
			System.out.println("Server err: " + e.getMessage());
			e.printStackTrace();
		}
	}

}
