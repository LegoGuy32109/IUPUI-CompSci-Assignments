/*
 * User.java
 * 
 * A abstract class for concrete types of User to inheirt from.
 * It specifies basic methods all User children should have, including
 * the acivateMenu method to return a specific menu for whichever
 * User type calls it, Admin or Customer.
 */

package a3.common;

import java.io.Serializable;
import java.util.Scanner;

public interface User extends Serializable{

    // Return the name of the user
    public String getName();

    // Set the name of the user to newName
    public void setName(String newName);

    // Acvivate a menu specific to the concrete User's child's type
    public void activateMenu(Scanner readObj, FrontController controller);
}
