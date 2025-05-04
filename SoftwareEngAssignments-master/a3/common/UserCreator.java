/*
 * UserCreator.java
 * 
 * A abstract class for concrete types of User to implement.
 * It only specifies a generic createUser method that will create
 * Customers or Admins.
 */

package a3.common;

public interface UserCreator {

    // Create a User with userName and return it
    public User createUser(String userName);

}
