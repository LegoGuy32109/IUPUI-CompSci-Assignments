/*
 * Item.java
 * 
 * A class to represent an Item in the store system.
 */

package a3.common;

import java.io.Serializable;

public class Item implements Serializable{
    // Price in dollars of item
    public double price;
    // Quantity of the item in the store
    public int quantity;
    // A unique description of the item, is used to identify items in the system.
    public String desc;

    // Default item constructor
    public Item() {
        this.price = 0.0;
        this.quantity = 0;
        this.desc = "default description";
    }

    // Item constructor with specific parameters 
    public Item(String desc, double price, int quantity){
        this.desc = desc;
        this.price = price;
        this.quantity = quantity;
    }

}
