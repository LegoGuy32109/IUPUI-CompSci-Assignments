package a2.common;

import java.io.Serializable;

public class Item implements Serializable{
    public double price;
    public int quantity;
    public String desc;

    public Item() {
        this.price = 0.0;
        this.quantity = 0;
        this.desc = "default description";
    }

    public Item(String desc, double price, int quantity){
        this.desc = desc;
        this.price = price;
        this.quantity = quantity;
    }

    public boolean canBuy(int amount){
        if(this.quantity >= amount){
            return true;
        }
        return false;
    }
}
