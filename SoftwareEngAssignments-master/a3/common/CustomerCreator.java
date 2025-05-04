/*
 * CustomerCreator.java
 * 
 * A child of the UserCreator abstract, it specifically creates Customer Users.
 */

package a3.common;

public class CustomerCreator implements UserCreator {

    // Create a new Customer with userName and return it
    public User createUser(String userName) {
        return new Customer(userName);
    }

}
