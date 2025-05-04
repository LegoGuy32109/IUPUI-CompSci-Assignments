/*
 * AdminCreator.java
 * 
 * A child of the UserCreator abstract, it specifically creates Admin Users.
 */

package a3.common;

public class AdminCreator implements UserCreator {

    // Create an Admin with userName and return it
    public User createUser(String userName) {
        return new Admin(userName);
    }

}
