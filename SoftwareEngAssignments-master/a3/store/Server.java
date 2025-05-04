/*
 * Server.java
 * 
 * The server component recieving messages from a client, hosting the
 * RemoteStore object for the store system.
 */

package a3.store;

import java.rmi.*;
import a3.common.*;

public class Server {
	// main method to run the server
	public static void main(String args[]) {
		try {
			// the RemoteStore object
			StoreImpl remote_store = new RemoteStore();

			// admin creator to create default admin in system
			AdminCreator adminCreator = new AdminCreator();

			FrontController controller = new FrontController(remote_store);
			// Dummy items being added by default
			controller.addUser(adminCreator.createUser("admin"));
			controller.addItem(new Item("Apple", 1.20, 5));
			controller.addItem(new Item("Banana", 3.40, 12));
			controller.addItem(new Item("Baking Powder", 6.12, 7));

			// name is the server address of where the remoteStore object
			// is binded to and where the client finds it.
			String name = "//in-csci-rrpc03.cs.iupui.edu:2324/RemoteStore";
			Naming.rebind(name, remote_store);
			System.out.println(name);
			System.out.println("Store Server is ready");

		} catch (Exception e) {
			System.out.println("Server err: " + e.getMessage());
			e.printStackTrace();
		}
	}
}
