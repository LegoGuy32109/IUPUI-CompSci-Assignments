package a2.common;

import java.io.Serializable;

public class User implements Serializable{
    private String name;
    private boolean isAdmin;

    public User(){
        this.name = "default user";
        this.isAdmin = false;
    }

    public User(User copyUser){
        this.name = copyUser.getName();
        this.isAdmin = false;
    }

    public User(String name){
        this.name = name;
        this.isAdmin = false;
    }
    public User(String name, boolean isAdmin){
        this.name = name;
        this.isAdmin = isAdmin;
    }

    public String getName(){
        return this.name;
    };

    public void setName(String newName){
        this.name = newName;
    };

    public boolean isAdmin(){
        return isAdmin;
    };

}
