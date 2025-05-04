package a2.store;

import java.rmi.*;
import a2.common.*;

public class Server {
    // main method to run the server
	public static void main(String args[]) {
		try {
			// the RemoteStore object
			StoreImpl remote_store = new RemoteStore();

			// Dummy items being added by default
			remote_store.addUser(new User("admin", true));
			remote_store.addItem(new Item("Apple", 1.20, 5));
			remote_store.addItem(new Item("Banana", 3.40, 12));
			remote_store.addItem(new Item("Baking Powder", 6.12, 7));

			// name is the server address of where the remoteStore object
			// is binded to and where the client finds it.
			String name = "//in-csci-rrpc03.cs.iupui.edu:2323/RemoteStore";
			Naming.rebind(name, remote_store);
			System.out.println(name);
			System.out.println("Store Server is ready");

		} catch (Exception e) {
			System.out.println("Server err: " + e.getMessage());
			e.printStackTrace();
		}
	}
}
